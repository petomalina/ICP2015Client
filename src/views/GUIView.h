//
// Created by gelidus on 5.5.2015.
//

#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGraphicsScene>

#include "IView.h"
#include "gui/LabyrinthItem.h"

#ifndef ICP2015CLIENT_GUIVIEW_H
#define ICP2015CLIENT_GUIVIEW_H


class GUIView: public IView {

protected:
	QGraphicsView *view;
	QGraphicsScene *scene;

public:
	GUIView();
	~GUIView();

public:
	void show();
};


#endif //ICP2015CLIENT_GUIVIEW_H
