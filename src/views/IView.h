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
	bool running, initialized;

	std::string Name = "SaveGame";

	int PlayerCount;
	int PlaygroundSize;
	int CardCount;

	std::vector<Player *> Players;
	Player *OnMove, *Winner;

	std::vector<std::shared_ptr<Fragment>> Map;
	std::vector<Treasure> Treasures;

	std::shared_ptr<Fragment> MovingBlock;
	Vector2 LockedPosition;

	bool MovingPlayer;

	void clear() {
		this->running = false;
		this->initialized = false;

		this->Name = "";
		this->MovingBlock = nullptr;

		for (Player *plr: this->Players) {
			delete plr;
		}
		this->OnMove = nullptr;
		this->Winner = nullptr;
		this->MovingPlayer = false;
		this->LockedPosition.set(0, 0);

		this->Map.clear();
	}

	GameData *deepCopy() {
		GameData *data = new GameData();

		data->running = this->running;
		data->initialized = this->initialized;
		data->Name = this->Name;
		data->PlayerCount = this->PlayerCount;
		data->PlaygroundSize = this->PlaygroundSize;
		data->CardCount = this->CardCount;
		data->Players = this->Players;
		data->OnMove = this->OnMove;
		data->Winner = this->Winner;
		data->Map = this->Map;
		data->Treasures = this->Treasures;
		data->MovingBlock = this->MovingBlock;
		data->LockedPosition = this->LockedPosition;

		return data;
	}
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
	Event<std::string, int, int, int> onGameStart;

	// event fired on undo
	Event<> onUndo;

	// event fired on redo
	Event<> onRedo;

	// event fired on save
	Event<> onSave;

	Event<std::string> onLoad;
};


#endif //ICP2015CLIENT_IVIEW_H
