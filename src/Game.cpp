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

void Game::indexMovingBlock()
{
	if (this->pressedKey == KeyBindings::keyRight)
		this->movingBlockIndex += 1;
	else if (this->pressedKey == KeyBindings::keyLeft)
		this->movingBlockIndex -= 1;
	else
		return;

	adjustMovingBlockIndex();
}

void Game::adjustMovingBlockIndex()
{
	// Maximal size of indexes where moving block can be placed. (only even rows/cols on 4 sides)
	int maxIndex = (this->size / 2) * 4;
	if (this->movingBlockIndex >= maxIndex)
		this->movingBlockIndex = this->movingBlockIndex % maxIndex;
	else
		this->movingBlockIndex = maxIndex - this->movingBlockIndex;
}


