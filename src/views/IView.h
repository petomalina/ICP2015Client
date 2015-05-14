/**
 * @brief ICP project 2015 (Maze game)
 * @authors xmalin26, xmasek15
 */


#ifndef ICP2015CLIENT_IVIEW_H
#define ICP2015CLIENT_IVIEW_H

#include "../event/Event.h"
#include "Fragment.h"

#include "../models/Treasure.h"
#include "../models/CardPackGenerator.h"
#include "../models/Player.h"

/**
 * Main game data structure holding all entities for each game
 */
struct GameData {
	bool running;

	std::string Name;

	int PlayerCount;
	int PlaygroundSize;
	int CardCount;

	std::vector<Player *> Players;
	Player *OnMove;

	std::vector<Fragment *> Map;
	std::vector<Treasure> Treasures;

	Fragment *MovingBlock, *LastMovedBlock;

	bool MovingPlayer;
};

/**
 * Rotation for given object (or movement)
 */
enum class Rotation {
	Up, Down, Left, Right
};

/**
 * Interface class which encapsulates View functionality and
 * events used for the game logic
 */
class IView {

public:
	GameData *game;

public:
	/**
	 * Initializes the View with the GameData structure
	 * @param data GameData structure to operate with
	 */
	virtual void initialize(GameData *data) = 0;

	/**
	 * Shows the main view of the View
	 */
	virtual void show() = 0;

public:
	// rotation of character
	Event<Movement> onMove;

	Event<> onMoveEnter;

	Event<> onRotate;
	// number of players, size of playground
	Event<int, int, int> onGameStart;

	// event fired on undo
	Event<> onUndo;

	// event fired on redo
	Event<> onRedo;

	// event fired on save
	Event<> onSave;

	Event<std::string> onLoad;
};


#endif //ICP2015CLIENT_IVIEW_H
