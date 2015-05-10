//
// Created by gelidus on 14.3.2015.
//

#include "Game.h"

using namespace std::placeholders;

Game::Game(IView *view)
{
	this->view = view;
	this->view->initialize(&this->data);

	this->view->onMove(std::bind(&Game::onMove, this, _1));
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
	for (Fragment *fragment : this->data.Map) {
		delete fragment;
	}
	this->data.Map.clear();

	for (int x = 0; x < this->data.PlaygroundSize; x++) {
		for (int y = 0; y < this->data.PlaygroundSize; y++) {
			if (x == 0 && y == 0) {
				this->data.Map.push_back(FragmentFactory::create(x, y, FragmentType::L, FragmentRotation::Normal));
			}
			else if (x == 0 && y == this->data.PlaygroundSize - 1) {
				this->data.Map.push_back(FragmentFactory::create(x, y, FragmentType::L, FragmentRotation::Right));
			}
			else if (x == this->data.PlaygroundSize - 1 && y == 0) {
				this->data.Map.push_back(FragmentFactory::create(x, y, FragmentType::L, FragmentRotation::Left));
			}
			else if (x == this->data.PlaygroundSize - 1 && y == this->data.PlaygroundSize - 1) {
				this->data.Map.push_back(FragmentFactory::create(x, y, FragmentType::L, FragmentRotation::Flip));
			}
			else if (x % 2 == 0 && y % 2 == 0) {
				// calculate T-s
				if (x == 0) { // up
					this->data.Map.push_back(FragmentFactory::create(x, y, FragmentType::T, FragmentRotation::Normal));
				}
				else if (y == 0) { // left
					this->data.Map.push_back(FragmentFactory::create(x, y, FragmentType::T, FragmentRotation::Left));
				}
				else if (x == this->data.PlaygroundSize - 1) { // down
					this->data.Map.push_back(FragmentFactory::create(x, y, FragmentType::T, FragmentRotation::Flip));
				}
				else if (y == this->data.PlaygroundSize - 1) { // right
					this->data.Map.push_back(FragmentFactory::create(x, y, FragmentType::T, FragmentRotation::Right));
				}
				else { // all other (even col/row crossings)
					switch (rand() % 4) { // randomize T rotation
						case 0 :
							this->data.Map.push_back(FragmentFactory::create(x, y, FragmentType::T, FragmentRotation::Normal));
							break;
						case 1 :
							this->data.Map.push_back(FragmentFactory::create(x, y, FragmentType::T, FragmentRotation::Right));
							break;
						case 2 :
							this->data.Map.push_back(FragmentFactory::create(x, y, FragmentType::T, FragmentRotation::Left));
							break;
						case 3 :
							this->data.Map.push_back(FragmentFactory::create(x, y, FragmentType::T, FragmentRotation::Flip));
							break;
						default:
							this->data.Map.push_back(FragmentFactory::create(x, y, FragmentType::T, FragmentRotation::Normal));
							break;
					}
				}
			}
			else { // all other (odd rows/cols)
				this->data.Map.push_back(FragmentFactory::createRandom(x, y));
			}
		}
	}
}


void Game::generatePlayers()
{
	// clear all players
	for (Player *player : this->data.Players) {
		delete player;
	}
	this->data.Players.clear();

	CardPackGenerator cardPackGenerator{12};

	for (int i = 1; i <= this->data.PlayerCount; i++) {
		QPoint position{};
		switch (i) {
			case 1:
				position.setX(0);
				position.setY(0);
				break;

			case 2:
				position.setX(this->data.PlaygroundSize-1);
				position.setY(this->data.PlaygroundSize-1);
				break;

			case 3:
				position.setX(0);
				position.setY(this->data.PlaygroundSize-1);
				break;

			case 4:
				position.setX(this->data.PlaygroundSize-1);
				position.setY(0);

			default:
				break;
		}

		Player *p = new Player(i-1, position);
		cardPackGenerator.generatePack(p->Cards);
		this->data.Players.push_back(p);
	}
}

void Game::loadGame(GameData *data)
{

}

void Game::saveGame(GameData *data)
{

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
	int maxIndex = (this->data.PlaygroundSize / 2) * 4;
	if (this->movingBlockIndex >= maxIndex)
		this->movingBlockIndex = this->movingBlockIndex % maxIndex;
	else
		this->movingBlockIndex = maxIndex - this->movingBlockIndex;
}

void Game::onMove(Rotation rot)
{
	switch (rot) {
		case Rotation::Down:
			if (data.OnMove->getPosition().y() + 1 < data.PlaygroundSize) {
				this->data.OnMove->move(Movement::Down);
			}
			break;

		case Rotation::Up:
			if (data.OnMove->getPosition().y() > 0) {
				this->data.OnMove->move(Movement::Up);
			}
			break;

		case Rotation::Left:
			if (data.OnMove->getPosition().x() > 0) {
				this->data.OnMove->move(Movement::Left);
			}
			break;

		case Rotation::Right:
			if (data.OnMove->getPosition().x() + 1 < data.PlaygroundSize) {
				this->data.OnMove->move(Movement::Right);
			}
			break;
	}
}

void Game::onFragmentPlace(int index, FragmentType type, Rotation rot)
{

}

void Game::onGameStart(int players, int size)
{
	this->data.PlayerCount = players;
	this->data.PlaygroundSize = size;
	this->generateMap();
	this->generatePlayers();
	this->data.OnMove = *this->data.Players.begin();
}

void Game::onUndo()
{

}

void Game::onRedo()
{

}
