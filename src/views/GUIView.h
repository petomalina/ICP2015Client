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

	bool inGame;

public:
	GUIView();

	virtual ~GUIView();

public:
	virtual void initialize(GameData *data) override;

	/**
	 * Shows the view
	 */
	void show();

	/**
	 * Reflects changes in GameData to the view
	 */
	void reflect();

	/**
	 * Shows game scene
	 */
	void showGame();

	/**
	 * Shows game options scene
	 */
	void showGameOptions();

	/**
	 * Shows menu scene
	 */
	void showMenu();

protected: // geometry utils

	/**
	 * Creates simple menu for given scene and elements
	 * @param scene    scene to be populated
	 * @param elements elemenets to be added
	 */
	void createSimpleMenu(QGraphicsScene *scene, std::vector<QWidget *> &elements);

	/**
	 * Creates simple menu for given scene and elements
	 * @param scene    scene to be populated
	 * @param elements elemenets to be added
	 */
	void createDoubleMenu(QGraphicsScene *scene, std::vector<QWidget *> &elements);

private slots:

	/**
	 * Handles button for new game
	 */
	void handleNewGameButton();

	/**
	 * Handles load button
	 */
	void handleLoadGameButton();

	/**
	 * Handles game save button
	 */
	void handleSaveGameButton();

	/**
	 * Handles Exit button
	 */
	void handleExitButton();

	/**
	 * Handles game start button
	 */
	void handleGameStartButton();

	/**
	 * Handles changes in player combo box
	 * @param text changed text
	 */
	void handlePlayersChange(const QString &text);

	/**
	 * Handles changes of playground size inputs
	 * @param text current size
	 */
	void handleSizeChange(const QString &text);

	/**
	 * Handles changes in cards combo box
	 * @param text current value
	 */
	void handleCardsChange(const QString &text);

protected:
	virtual void keyPressEvent(QKeyEvent *event) override;

};


#endif //ICP2015CLIENT_GUIVIEW_H
