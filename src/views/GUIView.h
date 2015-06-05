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

/**
 * @brief GUI view class
 * @details Provides game gui using Qt library over separated game logic
 * @return view that will be reflected as game
 */
class GUIView: public QGraphicsView, public IView {
Q_OBJECT

protected:
	QGraphicsScene *menuScene, *gameScene, *gameOptionsScene, *winScene;
	// menu elements
	std::vector<QWidget *> menuElements, gameOptionsElements, winSceneElements;

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
	 * @brief Shows the view
	 */
	void show();

	/**
	 * @brief Reflects changes in GameData to the view
	 */
	void reflect();

	/**
	 * @brief Shows game scene
	 */
	void showGame();

	/**
	 * @brief Shows game options scene
	 */
	void showGameOptions();

	/**
	 * @brief Shows menu scene
	 */
	void showMenu();

	/**
	 * @brief Shows win scene
	 */
	void showWin();

protected: // geometry utils

	/**
	 * @brief Creates simple menu for given scene and elements
	 * @param scene    scene to be populated
	 * @param elements elements to be added
	 */
	void createSimpleMenu(QGraphicsScene *scene, std::vector<QWidget *> &elements);

	/**
	 * @brief Creates simple menu for given scene and elements
	 * @param scene    scene to be populated
	 * @param elements elements to be added
	 */
	void createDoubleMenu(QGraphicsScene *scene, std::vector<QWidget *> &elements);

private slots:

	/**
	 * @brief Handles button for new game
	 */
	void handleNewGameButton();

	/**
	 * @brief Handles load button
	 */
	void handleLoadGameButton();

	/**
	 * @brief Handles game save button
	 */
	void handleSaveGameButton();

	/**
	 * @brief Handles Exit button
	 */
	void handleExitButton();

	/**
	 * @brief Handles game start button
	 */
	void handleGameStartButton();

	/**
	 * @brief Handles changes in player combo box
	 * @param text changed text
	 */
	void handlePlayersChange(const QString &text);

	/**
	 * @brief Handles changes of playground size inputs
	 * @param text current size
	 */
	void handleSizeChange(const QString &text);

	/**
	 * @brief Handles changes in cards combo box
	 * @param text current value
	 */
	void handleCardsChange(const QString &text);

protected:
	virtual void keyPressEvent(QKeyEvent *event) override;

};


#endif //ICP2015CLIENT_GUIVIEW_H
