//
// Created by gelidus on 7.5.2015.
//

#ifndef ICP2015CLIENT_IVIEW_H
#define ICP2015CLIENT_IVIEW_H

#include "../event/Event.h"
#include "Fragment.h"

#include "../models/CardPackGenerator.h"
#include "../models/Player.h"

struct GameData {
	std::string Name;

	int PlayerCount;
	int PlaygroundSize;

	std::vector<Player *> Players;
	Player *OnMove;

	std::vector<Fragment *> Map;
	Fragment *MovingBlock;

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
	Event<Rotation> onMove;
	// index and what type
	Event<int, FragmentType, Rotation> onFragmentPlace;
	// number of players, size of playground
	Event<int, int> onGameStart;

	Event<> onUndo;

	Event<> onRedo;

	Event<> onSave;
};


#endif //ICP2015CLIENT_IVIEW_H
