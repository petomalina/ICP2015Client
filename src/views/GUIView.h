//
// Created by gelidus on 5.5.2015.
//

#ifndef ICP2015CLIENT_GUIVIEW_H
#define ICP2015CLIENT_GUIVIEW_H

#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QInputDialog>
#include <QtWidgets/QTextEdit>
#include <QtCore/QObject>

#include "IView.h"
#include "gui/LabyrinthItem.h"

class GUIView: public QObject, public IView {
Q_OBJECT

protected:
	QGraphicsView *view;
	QGraphicsScene *menuScene, *gameScene, *gameOptionsScene;

	int size;

	// menu elements
	std::vector<QWidget*> menuElements;

	// game elements
	std::vector<LabyrinthItem*> fragments;

public:
	GUIView(int size);
	virtual ~GUIView();

public:
	void initialize();

	void show();

	void showGame();

	void showGameOptions();

	void showMenu();

	void generateMap();

protected: // geometry utils
	void createSimpleMenu(QGraphicsScene *scene, std::vector<QWidget*> &elements);

	void createDoubleMenu(QGraphicsScene *scene, std::vector<QWidget*> &elements);

private slots:
	void handleNewGameButton();

	void handleLoadGameButton();

	void handleExitButton();

};


#endif //ICP2015CLIENT_GUIVIEW_H
