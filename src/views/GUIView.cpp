//
// Created by gelidus on 5.5.2015.
//

#include <QtCore/qcoreevent.h>
#include <iostream>
#include <QtCore/qcoreapplication.h>
#include "GUIView.h"

GUIView::GUIView(int size)
{
	this->size = size;

	// +1 so we can manipulate with one more stone
	qreal pixelWidth = (this->size + 1) * LabyrinthItem::Width;
	// +2 so we can manipulate with stone and add some stats
	qreal pixelHeight = (this->size + 2) * LabyrinthItem::Height;

	this->menuScene = new QGraphicsScene{0, 0, pixelWidth, pixelHeight};
	this->gameScene = new QGraphicsScene{0, 0, pixelWidth, pixelHeight};
	this->gameOptionsScene = new QGraphicsScene{0, 0, pixelWidth, pixelHeight};
	this->scale(1.5, 1.5);

	SContentManager.addTexture("I", "graphics/I.png");
	SContentManager.addTexture("L", "graphics/L.png");
	SContentManager.addTexture("T", "graphics/T.png");

	this->showMenu();
}

GUIView::~GUIView()
{
}


void GUIView::initialize()
{
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
	playersInput->addItems({ "4", "3", "2", "1" });
	this->gameOptionsElements.push_back(playersInput);

	QLabel *playSize = new QLabel{"Playground: "};
	this->gameOptionsElements.push_back(playSize);

	QComboBox *sizeInput = new QComboBox{};
	sizeInput->addItems({"7", "5", "9", "11"});
	this->gameOptionsElements.push_back(sizeInput);

	QPushButton *startButton = new QPushButton{"Start game"};
	connect(startButton, SIGNAL(released()), this, SLOT(handleGameStartButton()));
	this->gameOptionsElements.push_back(startButton);

	this->createDoubleMenu(this->gameOptionsScene, this->gameOptionsElements);


	/* GAME INITIALIZATION */
	this->generateMap();
};


void GUIView::show()
{
	QGraphicsView::show();
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

void GUIView::generateMap()
{
	for (int x = 0; x < size; x++) {
		for (int y = 0; y < size; y++) {
			fragments.push_back(new LabyrinthItem(SContentManager.getTexture("L")));
			if (x == 0 && y == 0) {
			} else if (x == 0 && y == size-1) {

			} else if (x == size -1 && y == 0) {

			} else if (x == size -1 && y == size -1) {

			} else if (x % 2 == 0 && y % 2 == 0) {
				// calculate T-s
				if (x == 0) { // up

				} else if (y == 0) { // left

				} else if (x == size -1) { // down

				} else if (y == size -1) { // right

				}

			} else if (x % 2 != 0 && y % 2 != 0) {
				// randomize
			}
		}
	}
}


void GUIView::createSimpleMenu(QGraphicsScene *scene, std::vector<QWidget *> &elements)
{
	const int sceneCenterX = (int)scene->width() / 2;
	const int buttonWidth = 120;
	const int buttonHeight = 25;

	const int menuStartOffset = (int)scene->height() / 8;

	int index = 1;
	for (QWidget *widget : elements) {
		widget->setGeometry(QRect{QPoint{ sceneCenterX - buttonWidth/2, menuStartOffset + (buttonHeight + 10)*index}, QSize{buttonWidth, buttonHeight}});

		scene->addWidget(widget);
		index++;
	}
}

void GUIView::createDoubleMenu(QGraphicsScene *scene, std::vector<QWidget *> &elements)
{
	const int sceneCenterX = (int)scene->width() / 2;
	const int buttonWidth = 120;
	const int buttonHeight = 25;

	const int menuStartOffset = (int)scene->height() / 8;

	int elemIndex = 1;
	int index = 1;
	for (QWidget *widget : elements) {
		int offsetX = (elemIndex % 2 == 0) ? sceneCenterX + 10 : sceneCenterX - buttonWidth -10;
		widget->setGeometry(QRect{QPoint{ offsetX, menuStartOffset + (buttonHeight + 10)* index}, QSize{buttonWidth, buttonHeight}});

		scene->addWidget(widget);
		if (elemIndex % 2 == 0) {
			index++;
		}
		elemIndex++;
	}
}

void GUIView::handleNewGameButton(){
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
	QComboBox *players = qobject_cast<QComboBox*>(this->gameOptionsElements[3]);
	this->players = atoi(players->currentText().toStdString().c_str());
	this->onGameStart.dispatch(this->players, this->size);
	this->showGame();
}


void GUIView::keyPressEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_Escape) {
		this->showMenu();
	}
}
