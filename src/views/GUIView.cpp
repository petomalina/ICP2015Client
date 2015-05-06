//
// Created by gelidus on 5.5.2015.
//

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
	this->view = new QGraphicsView{this->menuScene};
	this->view->scale(1.7, 1.7);
}

GUIView::~GUIView()
{
	delete this->view;
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

	/* GAME INITIALIZATION */
	this->generateMap();
};

void GUIView::show()
{
	this->view->show();
}


void GUIView::showGame()
{
	this->view->setScene(this->gameScene);
}

void GUIView::showGameOptions()
{
	this->view->setScene(this->gameOptionsScene);
}

void GUIView::showMenu()
{
	this->view->setScene(this->menuScene);
}

void GUIView::generateMap()
{
}


void GUIView::createSimpleMenu(QGraphicsScene *scene, std::vector<QWidget *> &elements)
{
	const int sceneCenterX = (int)scene->width() / 2;
	const int buttonWidth = 100;
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
	const int buttonWidth = 100;
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
	this->view->close();
}
