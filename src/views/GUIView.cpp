//
// Created by gelidus on 5.5.2015.
//

#include "GUIView.h"

GUIView::GUIView(int size)
{
	this->scene = new QGraphicsScene{};
	this->view = new QGraphicsView{this->scene};

	this->size = size;
}

GUIView::~GUIView()
{
	delete this->view;
}

void GUIView::show()
{
	this->view->show();
}

void GUIView::generateMap()
{

}
