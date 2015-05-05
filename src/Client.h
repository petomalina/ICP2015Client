//
// Created by gelidus on 14.3.2015.
//

#ifndef _ICP2015CLIENT_CLIENT_H_
#define _ICP2015CLIENT_CLIENT_H_

#include "views/GUIView.h"
#include "views/CLIView.h"

enum class ReturnCode: int {
	OK = 0,
	ERROR_INIT,
	ERROR_CONNECT
};

class Client {

public:
	Client();

	~Client();

public:
	ReturnCode run();
};


#endif //_ICP2015CLIENT_CLIENT_H_
