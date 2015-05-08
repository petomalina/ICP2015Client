//
// Created by gelidus on 14.3.2015.
//

#include "Game.h"

using namespace std::placeholders;

Game::Game(IView *view)
{
	this->view = view;
	this->view->initialize();

	this->view->onCharacterMove(std::bind(&Game::onPlayerMove, this, _1));
	this->view->onFragmentPlace(std::bind(&Game::onFragmentPlace, this, _3));
	this->view->onGameStart(std::bind(&Game::onGameStart, this, _2));

	this->view->onUndo(std::bind(&Game::onUndo, this));
	this->view->onRedo(std::bind(&Game::onRedo, this));
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

void Game::onPlayerMove(Rotation rot)
{

}

void Game::onFragmentPlace(int index, FragmentType type, Rotation rot)
{

}

void Game::onGameStart(int players, int size)
{

}

void Game::onUndo()
{

}

void Game::onRedo()
{

}
