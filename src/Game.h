//
// Created by gelidus on 14.3.2015.
//

#ifndef _ICP2015CLIENT_CLIENT_H_
#define _ICP2015CLIENT_CLIENT_H_

#include <map>
#include <string>

#include "views/GUIView.h"
#include "views/CLIView.h"
#include "models/CardPackGenerator.h"
#include "models/Player.h"


enum class ReturnCode: int {
	OK = 0,
	ERROR_INIT,
	ERROR_CONNECT
};

enum class KeyBindings: int {
	keyEscape = 0x01000000,
	keyBackspace = 0x01000003,
	keyEnter = 0x01000005,
	keyF1 = 0x01000030,
	keySpace = 0x20,
	keyLeft = 0x01000012,
	keyUp = 0x01000013,
	keyRight = 0x01000014,
	keyDown = 0x01000015,
	key0 = 0x30,
	key1 = 0x31,
	key2 = 0x32,
	key3 = 0x33,
	key4 = 0x34,
	key5 = 0x35,
	key6 = 0x36,
	key7 = 0x37,
	key8 = 0x38,
	key9 = 0x39,
	keyC = 0x43,
	keyD = 0x44,
	keyE = 0x45,
	keyV = 0x56,
};

class Game {
protected:
	IView *view;

	int playersCount, size;
	std::vector<std::string> playersNames;
	int movingBlockIndex;
	KeyBindings pressedKey;
	std::map<int, Player*> players;

public:
	Game(IView *view);

	~Game();

public:
	void run();

	void indexMovingBlock();

	void adjustMovingBlockIndex();
};


#endif //_ICP2015CLIENT_CLIENT_H_
