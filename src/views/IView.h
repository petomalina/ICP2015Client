/**
 * @brief ICP project 2015 (Maze game)
 * @authors xmalin26, xmasek15
 */


#ifndef ICP2015CLIENT_IVIEW_H
#define ICP2015CLIENT_IVIEW_H

#include "../event/Event.h"
#include "Fragment.h"

#include "../models/CardPackGenerator.h"
#include "../models/Player.h"

struct GameData {
	bool running;

	std::string Name;

	int PlayerCount;
	int PlaygroundSize;
	int CardCount;

	std::vector<Player *> Players;
	Player *OnMove;

	std::vector<Fragment *> Map;

	Fragment *MovingBlock, *LastMovedBlock;

	bool MovingPlayer;
};

enum class Rotation {
	Up, Down, Left, Right
};

class IView {

public:
	GameData *game;

public:
	virtual void initialize(GameData *data) = 0;

	virtual void show() = 0;

public:
	// rotation of character
	Event<Movement> onMove;

	Event<> onMoveEnter;

	Event<> onRotate;
	// number of players, size of playground
	Event<int, int, int> onGameStart;

	Event<> onUndo;

	Event<> onRedo;

	Event<> onSave;

	Event<std::string> onLoad;
};


#endif //ICP2015CLIENT_IVIEW_H
