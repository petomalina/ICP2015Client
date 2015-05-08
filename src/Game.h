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

class Game {

protected:
	IView *view;

	std::map<int, Player*> players;

public:
	Game(IView *view);

	~Game();

public:
	void run();
};


#endif //_ICP2015CLIENT_CLIENT_H_
