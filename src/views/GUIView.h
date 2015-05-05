//
// Created by gelidus on 5.5.2015.
//

#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QPushButton>
#include <QtCore/QObject>

#include "IView.h"
#include "gui/LabyrinthItem.h"

#ifndef ICP2015CLIENT_GUIVIEW_H
#define ICP2015CLIENT_GUIVIEW_H


class GUIView: public IView {

protected:
	QGraphicsView *view;
	QGraphicsScene *menuScene, *gameScene;

	int size;

	// menu elements
	std::vector<QWidget*> menuElements;

	// game elements

public:
	GUIView(int size);
	~GUIView();

public:
	void initialize();

	void show();

	void showGame();

	void showMenu();

	void generateMap();
};


#endif //ICP2015CLIENT_GUIVIEW_H
