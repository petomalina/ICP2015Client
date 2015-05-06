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
	QPushButton *startButton = new QPushButton{"Start Game"};
	connect(startButton, SIGNAL(released()), this, SLOT(handleStartButton()));
	this->menuElements.push_back(startButton);

	QPushButton *exitButton = new QPushButton{"Exit"};
	connect(exitButton, SIGNAL(released()), this, SLOT(handleExitButton()));
	this->menuElements.push_back(exitButton);


	const int sceneCenterX = (int)this->menuScene->width() / 2;
	const int buttonWidth = 100;
	const int buttonHeight = 25;

	const int menuStartOffset = this->view->height() / 8;

	// initialize menu scene
	int index = 1;
	for (QWidget *widget : this->menuElements) {
		widget->setGeometry(QRect{QPoint{ sceneCenterX - buttonWidth/2, menuStartOffset + (buttonHeight + 10)*index}, QSize{buttonWidth, buttonHeight}});

		this->menuScene->addWidget(widget);
		index++;
	}

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

void GUIView::showMenu()
{
	this->view->setScene(this->menuScene);
}

void GUIView::generateMap()
{
}

void GUIView::handleStartButton()
{
	this->showGame();
}

void GUIView::handleExitButton()
{
	this->view->close();
}
