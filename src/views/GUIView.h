//
// Created by gelidus on 5.5.2015.
//

#ifndef ICP2015CLIENT_GUIVIEW_H
#define ICP2015CLIENT_GUIVIEW_H

#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QComboBox>
#include <QtCore/QObject>

#include <QtGui/QKeyEvent>

#include "IView.h"
#include "gui/LabyrinthItem.h"

class GUIView: public QGraphicsView, public IView {
Q_OBJECT

protected:
	QGraphicsScene *menuScene, *gameScene, *gameOptionsScene;

	int size;

	// menu elements
	std::vector<QWidget*> menuElements, gameOptionsElements, gameElements;

	// game elements
	std::vector<LabyrinthItem*> fragments;

public:
	GUIView(int size);
	virtual ~GUIView();

public:
	virtual void initialize() override;

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

	void handleGameStartButton();

protected:
	virtual void keyPressEvent(QKeyEvent *event) override;

};


#endif //ICP2015CLIENT_GUIVIEW_H
