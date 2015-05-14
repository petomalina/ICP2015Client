/**
 * @brief ICP project 2015 (Maze game)
 * @authors xmalin26, xmasek15
 */


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
#include "gui/GUIBlock.h"
#include "../ContentManager.h"

class GUIView: public QGraphicsView, public IView {
Q_OBJECT

protected:
	QGraphicsScene *savedScene, *menuScene, *gameScene, *gameOptionsScene;
	// menu elements
	std::vector<QWidget *> menuElements, gameOptionsElements;

	std::vector<GUIBlock*> blocks, playerBlocks;
	GUIBlock *movingBlock;

	// menu inputs
	int playersInput, sizeInput, cardInput;
	std::string loadInput;

public:
	GUIView();

	virtual ~GUIView();

public:
	virtual void initialize(GameData *data) override;

	void show();

	void reflect();

	void showGame();

	void showGameOptions();

	void showMenu();

protected: // geometry utils
	void createSimpleMenu(QGraphicsScene *scene, std::vector<QWidget *> &elements);

	void createDoubleMenu(QGraphicsScene *scene, std::vector<QWidget *> &elements);

private slots:

	void handleNewGameButton();

	void handleLoadGameButton();

	void handleSaveGameButton();

	void handleExitButton();

	void handleGameStartButton();

	void handlePlayersChange(const QString &text);

	void handleSizeChange(const QString &text);

	void handleCardsChange(const QString &text);

protected:
	virtual void keyPressEvent(QKeyEvent *event) override;

};


#endif //ICP2015CLIENT_GUIVIEW_H
