//
// Created by gelidus on 14.3.2015.
//

#include "Game.h"

using namespace std::placeholders;

Game::Game(IView *view)
{
	this->view = view;

	this->data.MovingBlock = nullptr;
	this->data.OnMove = nullptr;
	this->data.MovingPlayer = false;
	this->view->initialize(&this->data);

	this->view->onMove(std::bind(&Game::onMove, this, _1));
	this->view->onMoveEnter(std::bind(&Game::onMoveEnter, this));
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

	if (this->data.MovingBlock != nullptr) {
		delete this->data.MovingBlock;
		this->data.MovingBlock = nullptr;
	}
	this->data.MovingBlock = new Fragment(-1, 2, FragmentType::T, FragmentRotation::Normal);

	for (int y = 0; y < this->data.PlaygroundSize; y++) {
		for (int x = 0; x < this->data.PlaygroundSize; x++) {
			if (x == 0 && y == 0) {
				this->data.Map.push_back(FragmentFactory::create(x, y, FragmentType::L, FragmentRotation::Normal));
			}
			else if (x == 0 && y == this->data.PlaygroundSize - 1) {
				this->data.Map.push_back(FragmentFactory::create(x, y, FragmentType::L, FragmentRotation::Left));
			}
			else if (x == this->data.PlaygroundSize - 1 && y == 0) {
				this->data.Map.push_back(FragmentFactory::create(x, y, FragmentType::L, FragmentRotation::Right));
			}
			else if (x == this->data.PlaygroundSize - 1 && y == this->data.PlaygroundSize - 1) {
				this->data.Map.push_back(FragmentFactory::create(x, y, FragmentType::L, FragmentRotation::Flip));
			}
			else if (x % 2 == 0 && y % 2 == 0) {
				// calculate T-s
				if (x == 0) { // left
					this->data.Map.push_back(FragmentFactory::create(x, y, FragmentType::T, FragmentRotation::Left));
				}
				else if (y == 0) { // up
					this->data.Map.push_back(FragmentFactory::create(x, y, FragmentType::T, FragmentRotation::Normal));
				}
				else if (x == this->data.PlaygroundSize - 1) { // right
					this->data.Map.push_back(FragmentFactory::create(x, y, FragmentType::T, FragmentRotation::Right));
				}
				else if (y == this->data.PlaygroundSize - 1) { // down
					this->data.Map.push_back(FragmentFactory::create(x, y, FragmentType::T, FragmentRotation::Flip));
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
		Vector2 position{};
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

void Game::onMove(Movement mov)
{
	if (this->data.MovingPlayer) {
		Vector2 p = data.OnMove->getPosition();
		if (p.y() + 1 == data.PlaygroundSize && mov == Movement::Down ||
				p.y() == 0 && mov == Movement::Up ||
				p.x() == 0 && mov == Movement::Left ||
				p.x() + 1 == data.PlaygroundSize && mov == Movement::Right) {
			return;
		}

		// next fragment calculation
		Fragment *nextFragment = nullptr, *thisFragment = this->data.Map[this->data.PlaygroundSize * p.y() + p.x()];
		switch (mov) {
			case Movement::Down:
				nextFragment = this->data.Map[this->data.PlaygroundSize * (p.y() + 1) + p.x()];
				if (!nextFragment->isOpenUp() || !thisFragment->isOpenDown()) {
					return;
				}
				break;

			case Movement::Up:
				nextFragment = this->data.Map[this->data.PlaygroundSize * (p.y() - 1) + p.x()];
				if (!nextFragment->isOpenDown() || !thisFragment->isOpenUp()) {
					return;
				}
				break;

			case Movement::Left:
				nextFragment = this->data.Map[this->data.PlaygroundSize * p.y() + p.x() - 1];
				if (!nextFragment->isOpenRight() || !thisFragment->isOpenLeft()) {
					return;
				}
				break;

			case Movement::Right:
				nextFragment = this->data.Map[this->data.PlaygroundSize * p.y() + p.x() + 1];
				if (!nextFragment->isOpenLeft() || !thisFragment->isOpenRight()) {
					return;
				}
				break;
		}

		switch (mov) {
			case Movement::Down:
				this->data.OnMove->move(Movement::Down);
				break;

			case Movement::Up:
				this->data.OnMove->move(Movement::Up);
				break;

			case Movement::Left:
				this->data.OnMove->move(Movement::Left);
				break;

			case Movement::Right:
				this->data.OnMove->move(Movement::Right);
				break;
		}
	} else { // moving block
		switch (mov) {
			case Movement::Down:

			case Movement::Up:
				break;

			case Movement::Right:
				this->data.MovingBlock->move(1, 0);
				break;

			case Movement::Left:
				this->data.MovingBlock->move(-1, 0);
				break;
		}
	}
}

void Game::onMoveEnter()
{
	this->data.MovingPlayer = !this->data.MovingPlayer;
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
