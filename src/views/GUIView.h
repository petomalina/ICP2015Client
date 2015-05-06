//
// Created by gelidus on 5.5.2015.
//

#ifndef ICP2015CLIENT_GUIVIEW_H
#define ICP2015CLIENT_GUIVIEW_H

#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QPushButton>
#include <QtCore/QObject>

#include "IView.h"
#include "gui/LabyrinthItem.h"

class GUIView: public QObject, public IView {
Q_OBJECT

protected:
	QGraphicsView *view;
	QGraphicsScene *menuScene, *gameScene;

	int size;

	// menu elements
	std::vector<QWidget*> menuElements;

	// game elements

public:
	GUIView(int size);
	virtual ~GUIView();

public:
	void initialize();

	void show();

	void showGame();

	void showMenu();

	void generateMap();

private slots:
	void handleStartButton();

	void handleExitButton();

};


#endif //ICP2015CLIENT_GUIVIEW_H
