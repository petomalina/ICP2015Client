//
// Created by gelidus on 5.5.2015.
//

#include "GUIView.h"

GUIView::GUIView(int size)
{
	this->menuScene = new QGraphicsScene{0, 0, 800, 600};
	this->gameScene = new QGraphicsScene{0, 0, 800, 600};
	this->view = new QGraphicsView{this->menuScene};

	this->size = size;
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
	const int buttonWidth = 150;
	const int buttonHeight = 40;

	// initialize menu scene
	int index = 1;
	for (QWidget *widget : this->menuElements) {
		widget->setGeometry(QRect{QPoint{ sceneCenterX - buttonWidth/2, 200 + 50*index}, QSize{buttonWidth, buttonHeight}});

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
