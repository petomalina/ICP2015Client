//
// Created by gelidus on 5.5.2015.
//

#include "GUIView.h"

GUIView::GUIView(QGraphicsScene *scene)
{
	this->view = new QGraphicsView{scene};
}

GUIView::~GUIView()
{
	delete this->view;
}

void GUIView::show()
{
	this->view->show();
}
