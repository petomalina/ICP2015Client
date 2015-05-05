//
// Created by gelidus on 5.5.2015.
//

#include "GUIView.h"

GUIView::GUIView()
{
	this->scene = new QGraphicsScene{};
	this->view = new QGraphicsView{this->scene};
}

GUIView::~GUIView()
{
	delete this->view;
}

void GUIView::show()
{
	this->view->show();
}
