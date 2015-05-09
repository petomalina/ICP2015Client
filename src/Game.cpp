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
	this->view->onFragmentPlace(std::bind(&Game::onFragmentPlace, this, _1, _2, _3));
	this->view->onGameStart(std::bind(&Game::onGameStart, this, _1, _2));

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


void Game::generateMap()
{
	// clear map before generating
	for (Fragment *fragment : this->data->Map) {
		delete fragment;
	}
	this->data->Map.clear();

	for (int x = 0; x < this->data->PlaygroundSize; x++) {
		for (int y = 0; y < this->data->PlaygroundSize; y++) {
			if (x == 0 && y == 0) {
				this->data->Map.push_back(FragmentFactory::create(x, y, FragmentType::L, FragmentRotation::Normal));
			}
			else if (x == 0 && y == this->data->PlaygroundSize - 1) {
				this->data->Map.push_back(FragmentFactory::create(x, y, FragmentType::L, FragmentRotation::Right));
			}
			else if (x == this->data->PlaygroundSize - 1 && y == 0) {
				this->data->Map.push_back(FragmentFactory::create(x, y, FragmentType::L, FragmentRotation::Left));
			}
			else if (x == this->data->PlaygroundSize - 1 && y == this->data->PlaygroundSize - 1) {
				this->data->Map.push_back(FragmentFactory::create(x, y, FragmentType::L, FragmentRotation::Flip));
			}
			else if (x % 2 == 0 && y % 2 == 0) {
				// calculate T-s
				if (x == 0) { // up
					this->data->Map.push_back(FragmentFactory::create(x, y, FragmentType::T, FragmentRotation::Normal));
				}
				else if (y == 0) { // left
					this->data->Map.push_back(FragmentFactory::create(x, y, FragmentType::T, FragmentRotation::Left));
				}
				else if (x == this->data->PlaygroundSize - 1) { // down
					this->data->Map.push_back(FragmentFactory::create(x, y, FragmentType::T, FragmentRotation::Flip));
				}
				else if (y == this->data->PlaygroundSize - 1) { // right
					this->data->Map.push_back(FragmentFactory::create(x, y, FragmentType::T, FragmentRotation::Right));
				}
				else { // all other (even col/row crossings)
					switch (rand() % 4) { // randomize T rotation
						case 0 :
							this->data->Map.push_back(FragmentFactory::create(x, y, FragmentType::T, FragmentRotation::Normal));
							break;
						case 1 :
							this->data->Map.push_back(FragmentFactory::create(x, y, FragmentType::T, FragmentRotation::Right));
							break;
						case 2 :
							this->data->Map.push_back(FragmentFactory::create(x, y, FragmentType::T, FragmentRotation::Left));
							break;
						case 3 :
							this->data->Map.push_back(FragmentFactory::create(x, y, FragmentType::T, FragmentRotation::Flip));
							break;
						default:
							break;
					}
				}
			}
			else { // all other (odd rows/cols)
				this->data->Map.push_back(FragmentFactory::createRandom(x, y));
			}
		}
	}
}


void Game::generatePlayers()
{
	// clear all players
	for (Player *player : this->data->Players) {
		delete player;
	}
	this->data->Players.clear();

	for (int i = 1; i <= this->data->PlayerCount; i++) {
		// TODO: Calculate position of player
		this->data->Players.push_back(new Player(static_cast<int>(pow(i, 2)), QPoint{}));
	}
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
	int maxIndex = (this->data->PlaygroundSize / 2) * 4;
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
	this->data->PlayerCount = players;
	this->data->PlaygroundSize = size;
	this->generateMap();
}

void Game::onUndo()
{

}

void Game::onRedo()
{

}
