//
// Created by gelidus on 5.5.2015.
//

#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGraphicsScene>

#ifndef ICP2015CLIENT_GUIVIEW_H
#define ICP2015CLIENT_GUIVIEW_H


class GUIView {

protected:
	QGraphicsView *view;

public:
	GUIView(QGraphicsScene *scene);
	~GUIView();

public:
	void show();
};


#endif //ICP2015CLIENT_GUIVIEW_H
