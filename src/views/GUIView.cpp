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
	//QObject::connect(startButton, SIGNAL(released()), this, SLOT(showGame()));
	this->menuElements.push_back(startButton);
	// TODO : push more items
	this->menuElements.push_back(new QPushButton{"Exit"});


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
