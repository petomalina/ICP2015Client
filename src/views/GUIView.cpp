//
// Created by gelidus on 5.5.2015.
//

#include <QtCore/qcoreevent.h>
#include <iostream>
#include <QtCore/qcoreapplication.h>
#include "GUIView.h"

GUIView::GUIView()
{
	// set defaults
	this->playersInput = 4;
	this->sizeInput = 7;
	this->cardInput = 12;
	this->savedScene = nullptr;

	this->menuScene = new QGraphicsScene{0, 0, 800, 600};
	this->gameOptionsScene = new QGraphicsScene{0, 0, 800, 600};
	this->gameScene = nullptr;
	this->scale(1.5, 1.5);

	SContentManager.addTexture("I", "graphics/I.png");
	SContentManager.addTexture("L", "graphics/L.png");
	SContentManager.addTexture("T", "graphics/T.png");
	SContentManager.addTexture("P1", "graphics/P1.png");
	SContentManager.addTexture("P2", "graphics/P2.png");
	SContentManager.addTexture("P3", "graphics/P3.png");
	SContentManager.addTexture("P4", "graphics/P4.png");
}

GUIView::~GUIView()
{
}


void GUIView::initialize(GameData *data)
{
	this->game = data;

	/* MENU INITIALIZATION */
	QPushButton *newGameButton = new QPushButton{"New Game"};
	connect(newGameButton, SIGNAL(released()), this, SLOT(handleNewGameButton()));
	this->menuElements.push_back(newGameButton);

	QPushButton *loadGameButton = new QPushButton{"Load Game"};
	connect(loadGameButton, SIGNAL(released()), this, SLOT(handleLoadGameButton()));
	this->menuElements.push_back(loadGameButton);

	QPushButton *exitButton = new QPushButton{"Exit"};
	connect(exitButton, SIGNAL(released()), this, SLOT(handleExitButton()));
	this->menuElements.push_back(exitButton);

	this->createSimpleMenu(this->menuScene, this->menuElements);

	/* GAME OPTIONS INITIALIZATION */
	QLabel *nameLabel = new QLabel{"Game name: "};
	this->gameOptionsElements.push_back(nameLabel);

	QLineEdit *nameInput = new QLineEdit{};
	this->gameOptionsElements.push_back(nameInput);

	QLabel *playersLabel = new QLabel{"Players: "};
	this->gameOptionsElements.push_back(playersLabel);

	QComboBox *playersInput = new QComboBox{};
	playersInput->addItems({"4", "3", "2", "1"});
	connect(playersInput, SIGNAL(currentIndexChanged(
																	 const QString&)), this, SLOT(handlePlayersChange(
																																		const QString&)));
	this->gameOptionsElements.push_back(playersInput);

	QLabel *playSize = new QLabel{"Playground: "};
	this->gameOptionsElements.push_back(playSize);

	QComboBox *sizeInput = new QComboBox{};
	sizeInput->addItems({"7", "5", "9", "11"});
	connect(sizeInput, SIGNAL(currentIndexChanged(
																const QString&)), this, SLOT(handleSizeChange(
																																 const QString&)));
	this->gameOptionsElements.push_back(sizeInput);

	QLabel *cardCount = new QLabel{"Cards: "};
	this->gameOptionsElements.push_back(cardCount);

	QComboBox *cardInput = new QComboBox{};
	cardInput->addItems({"12", "24"});
	connect(cardInput, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(handleCardsChange(const QString&)));
	this->gameOptionsElements.push_back(cardInput);

	QPushButton *startButton = new QPushButton{"Start game"};
	connect(startButton, SIGNAL(released()), this, SLOT(handleGameStartButton()));
	this->gameOptionsElements.push_back(startButton);

	this->createDoubleMenu(this->gameOptionsScene, this->gameOptionsElements);

	this->showMenu();
};


void GUIView::show()
{
	QGraphicsView::show();
}


void GUIView::reflect()
{
	for (GUIBlock *block : this->blocks) {
		delete block;
	}
	this->blocks.clear();

	for (GUIBlock *player : this->playerBlocks) {
		delete player;
	}
	this->playerBlocks.clear();

	if (this->gameScene != nullptr) {
		delete this->gameScene; // clear game scene
	}

	// +2 so we can manipulate with one more stone
	qreal pixelWidth = (this->game->PlaygroundSize + 2) * GUIBlock::Size;
	// +3 so we can manipulate with stone and add some stats
	qreal pixelHeight = (this->game->PlaygroundSize + 3) * GUIBlock::Size;

	this->gameScene = new QGraphicsScene{0, 0, pixelWidth, pixelHeight};

	for (Fragment *frag : this->game->Map) {
		auto block = new GUIBlock(frag);
		this->blocks.push_back(block);
		this->gameScene->addItem(block);
	}

	int playerIndex = 1;
	for (Player *player : this->game->Players) {
		auto block = new GUIBlock(
				new Fragment(player->getPosition().x(), player->getPosition().y(), FragmentType::Player,
										 FragmentRotation::Normal),
				SContentManager.getTexture("P" + std::to_string(playerIndex))
		);

		this->playerBlocks.push_back(block);
		this->gameScene->addItem(block);

		playerIndex++;
	}


	// init moving block
	this->movingBlock = new GUIBlock(this->game->MovingBlock);
	this->gameScene->addItem(this->movingBlock);
}

void GUIView::showGame()
{
	this->setScene(this->gameScene);
}

void GUIView::showGameOptions()
{
	this->setScene(this->gameOptionsScene);
}

void GUIView::showMenu()
{
	this->setScene(this->menuScene);
}

void GUIView::createSimpleMenu(QGraphicsScene *scene, std::vector<QWidget *> &elements)
{
	const int sceneCenterX = (int) scene->width() / 2;
	const int buttonWidth = 120;
	const int buttonHeight = 25;

	const int menuStartOffset = (int) scene->height() / 4;

	int index = 1;
	for (QWidget *widget : elements) {
		widget->setGeometry(QRect{QPoint{sceneCenterX - buttonWidth / 2, menuStartOffset + (buttonHeight + 10) * index},
															QSize{buttonWidth, buttonHeight}});

		scene->addWidget(widget);
		index++;
	}
}

void GUIView::createDoubleMenu(QGraphicsScene *scene, std::vector<QWidget *> &elements)
{
	const int sceneCenterX = (int) scene->width() / 2;
	const int buttonWidth = 120;
	const int buttonHeight = 25;

	const int menuStartOffset = (int) scene->height() / 4;

	int elemIndex = 1;
	int index = 1;
	for (QWidget *widget : elements) {
		int offsetX = (elemIndex % 2 == 0) ? sceneCenterX + 10 : sceneCenterX - buttonWidth - 10;
		widget->setGeometry(
				QRect{QPoint{offsetX, menuStartOffset + (buttonHeight + 10) * index}, QSize{buttonWidth, buttonHeight}});

		scene->addWidget(widget);
		if (elemIndex % 2 == 0) {
			index++;
		}
		elemIndex++;
	}
}

void GUIView::handleNewGameButton()
{
	this->showGameOptions();
}


void GUIView::handleLoadGameButton()
{

}

void GUIView::handleExitButton()
{
	this->close();
}

void GUIView::handleGameStartButton()
{
	this->onGameStart.dispatch(this->playersInput, this->sizeInput, this->cardInput);

	this->reflect(); // reflect fragments into game
	this->showGame();
}

void GUIView::handlePlayersChange(const QString &text)
{
	this->playersInput = atoi(text.toStdString().c_str());
}

void GUIView::handleSizeChange(const QString &text)
{
	this->sizeInput = atoi(text.toStdString().c_str());
}


void GUIView::handleCardsChange(const QString &text)
{
	this->cardInput = atoi(text.toStdString().c_str());
}

void GUIView::keyPressEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_Escape) {
		if (this->savedScene == nullptr) {
			this->savedScene = this->scene();
			this->setScene(this->menuScene);
		}
		else {
			this->setScene(this->savedScene);
			this->savedScene = nullptr;
		}
	}

	// event binsings
	if (event->key() == Qt::Key_Down) {
		this->onMove(Movement::Down);
	} else if (event->key() == Qt::Key_Up) {
		this->onMove(Movement::Up);
	} else if (event->key() == Qt::Key_Left) {
		this->onMove(Movement::Left);
	} else if (event->key() == Qt::Key_Right) {
		this->onMove(Movement::Right);
	}

	if (event->key() == Qt::Key_R) {
		this->onRotate();
	}

	if (this->game->MovingPlayer) {
		GUIBlock *playerBlock = this->playerBlocks[this->game->OnMove->Index];
		playerBlock->setPosition(this->game->OnMove->getPosition().x(), this->game->OnMove->getPosition().y());
	} else {
		this->movingBlock->setPosition(this->game->MovingBlock->getX(), this->game->MovingBlock->getY());this->movingBlock->rotate(this->game->MovingBlock->getRotation());
	}

	if (event->key() == Qt::Key_Enter) {
		this->onMoveEnter();
	}
}
