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

class Game {
protected:
	IView *view;

	int movingBlockIndex;

#ifdef CLI_MODE
	KeyBindings pressedKey;
#endif

	std::vector<Vector2> movingBlockPositions;
	std::vector<Vector2>::iterator movingBlockPosition;

public:
	GameData data; // this should be only for friends

public:
	Game(IView *view);

	~Game();

private:
	void generateMap();

	void generatePlayers();

	void loadGame(std::string name);

	void saveGame();

public:
	void run();

public:
	void onMove(Movement mov);

	void onMoveEnter();

	void onRotate();

	void onGameStart(int players, int size, int cards);

	void onUndo();

	void onRedo();
};


#endif //_ICP2015CLIENT_CLIENT_H_
