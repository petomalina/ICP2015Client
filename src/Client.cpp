//
// Created by gelidus on 14.3.2015.
//

#include "Client.h"


Client::Client(IView *view)
{
	this->view = view;
}

Client::~Client()
{

}

void Client::run()
{
	this->view->show();
}
