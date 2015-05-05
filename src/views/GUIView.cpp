//
// Created by gelidus on 5.5.2015.
//

#include "GUIView.h"

GUIView::GUIView(int size)
{
	this->menuScene = new QGraphicsScene{};
	this->gameScene = new QGraphicsScene{};
	this->view = new QGraphicsView{this->menuScene};
	this->view->resize(800, 600);

	this->size = size;
}

GUIView::~GUIView()
{
	delete this->view;
}


void GUIView::initialize()
{
}

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
