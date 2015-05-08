//
// Created by gelidus on 14.3.2015.
//

#include "Game.h"


Game::Game(IView *view)
{
	this->view = view;
	this->view->initialize();
}

Game::~Game()
{

}

void Game::run()
{
	this->view->show();
}
