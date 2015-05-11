//
// Created by gelidus on 14.3.2015.
//

#ifndef _ICP2015CLIENT_CLIENT_H_
#define _ICP2015CLIENT_CLIENT_H_

#include <map>
#include <string>
#include <math.h>

#include "views/GUIView.h"
#include "views/CLIView.h"

class Game {
protected:
	IView *view;

	int movingBlockIndex;
	KeyBindings pressedKey;

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

	void loadGame(GameData *data);

	void saveGame(GameData *data);

public:
	void run();

public:
	void onMove(Movement mov);

	void onMoveEnter();

	void onRotate();

	void onFragmentPlace(int index, FragmentType type, Rotation rot);

	void onGameStart(int players, int size, int cards);

	void onUndo();

	void onRedo();
};


#endif //_ICP2015CLIENT_CLIENT_H_
