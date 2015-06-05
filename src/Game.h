/**
 * @brief ICP project 2015 (Maze game)
 * @authors xmalin26, xmasek15
 */

#ifndef _ICP2015CLIENT_CLIENT_H_
#define _ICP2015CLIENT_CLIENT_H_

#include <map>
#include <string>
#include <math.h>
#include <fstream>
#include <iostream>

#ifdef CLI_MODE

#include "views/CLIView.h"

#else

#include "views/GUIView.h"

#endif

/**
 * Game class is main class which operates at given view (cli or gui)
 * It encapsulates all game logic
 */
class Game {
protected:
	IView *view;

#ifdef CLI_MODE
	KeyBindings pressedKey;
#endif

	std::vector<Vector2> movingBlockPositions;
	std::vector<Vector2>::iterator movingBlockPosition;

public:
	GameData *data; // this should be only for friends

	std::vector<GameData*> history;
	std::vector<GameData*>::iterator historian;

public:
	Game(IView *view);

	~Game();

	/**
	 * @brief Runs current game instance
	 */
	void run();

private:

	/* Main utilities*/

	void initGameData();

	/**
	 * @brief Generates map based on game data
	 */
	void generateMap();

	void generateMovingBlockPositions();

	/**
	 * @brief Gemerates players based on game data
	 */
	void generatePlayers();

	void generateTreasures();

	/**
	 * @brief Loads saved game
	 * @param name [description]
	 */
	void loadGame(std::string name);

	/**
	 * @brief Saves current game
	 */
	void saveGame();

	/**
	 * @brief Handles request for undo last change
	 */
	void undo();

	void redo();

	/* Game logic helpers */

	/**
	 * @brief Pushes current moving block into the game
	 */
	bool pushBlock();

	/* Events */

	/**
	 * @brief Event fired when player or block moves
	 * @param mov rotation of fragment
	 */
	void onMove(Movement mov);

	/**
	 * @brief Event fired when move is finished
	 */
	void onMoveEnter();

	/**
	 * @brief Event fired on fragment rotation
	 */
	void onRotate();

	/**
	 * @brief Event fired on game start
	 * @param players number of players in the Game
	 * @param size    size of playground
	 * @param cards   number of cards
	 */
	void onGameStart(std::string name, int players, int size, int cards);


	void pushHistory();

	/**
	 * @brief Event fired when undo is requested
	 */
	void onUndo();

	void onRedo();

	void onSaveGame();

	void onLoadGame(std::string name);

	void movePlayersOnFragment(std::shared_ptr<Fragment> frag, Vector2 &mov);

	void calculateCollisions();

	void calculateMatchEndingConditions();
};


#endif //_ICP2015CLIENT_CLIENT_H_
