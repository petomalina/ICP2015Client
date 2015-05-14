/**
 * @brief ICP project 2015 (Maze game)
 * @authors xmalin26, xmasek15
 */

#include "Game.h"

using namespace std::placeholders;

Game::Game(IView *view)
{
	this->data.running = false;
	this->view = view;

	this->data.MovingBlock = nullptr;
	this->data.OnMove = nullptr;
	this->data.MovingPlayer = false;
	this->view->initialize(&this->data);

	this->view->onMove(std::bind(&Game::onMove, this, _1));
	this->view->onMoveEnter(std::bind(&Game::onMoveEnter, this));
	this->view->onRotate(std::bind(&Game::onRotate, this));
	this->view->onGameStart(std::bind(&Game::onGameStart, this, _1, _2, _3));

	this->view->onSave(std::bind(&Game::onSaveGame, this));
	this->view->onLoad(std::bind(&Game::onLoadGame, this, _1));

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
	this->data.MovingBlock = FragmentFactory::createRandom(1, -1);

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

	// index generation for moving block
	int x = 1, y = 1;
	for (; x < this->data.PlaygroundSize-1; x++) {
		if (x % 2 == 1) {
			this->movingBlockPositions.push_back(Vector2{x, -1});
		}
	}

	for (; y < this->data.PlaygroundSize-1; y++) {
		if (y % 2 == 1) {
			this->movingBlockPositions.push_back(Vector2{this->data.PlaygroundSize, y});
		}
	}

	for (; x > 0; x--) {
		if (x % 2 == 1) {
			this->movingBlockPositions.push_back(Vector2{x, this->data.PlaygroundSize});
		}
	}

	for (; y > 0; y--) {
		if (y % 2 == 1) {
			this->movingBlockPositions.push_back(Vector2{-1, y});
		}
	}

	this->movingBlockPosition = this->movingBlockPositions.begin();
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

void Game::loadGame(std::string name)
{
	std::string line;
	std::string savePath = "games/" + name + ".save";
	std::ifstream saveFile{savePath};


	saveFile.close();
}

void Game::saveGame()
{
	if (!this->data.running) {
		return;
	}

	if (this->data.Name == "") {
		this->data.Name = "NewGame";
	}

	std::string savePath = "games/" + this->data.Name + ".save";
	std::ofstream saveFile{savePath};

	// stream in
	saveFile << this->data.PlaygroundSize << ";" << this->data.CardCount << ";" << this->data.MovingPlayer << "\n";
	for (Fragment *frag : this->data.Map) {
		saveFile << frag->x() << ";" << frag->y() << ";" << static_cast<int>(frag->Type) << ";" << static_cast<int>(frag->getRotation()) << "\n";
	}

	saveFile << this->data.PlayerCount << ";" << this->data.OnMove->Index << "\n";
	for (Player *plr : this->data.Players) {
		saveFile << plr->Number << ";" << plr->Index << ";" << plr->getPosition().x() << ";" << plr->getPosition().y() << ";";
		for (Card &c : plr->Cards) {
			saveFile << static_cast<int>(c.getType()) << ";";
		}
	}

	saveFile.close();
}

void Game::pushBlock()
{
	Fragment *current = this->data.MovingBlock;
	this->data.LastMovedBlock = current;

	Vector2 move{0, 0};
	int row = -1, column = -1;

	if (current->getX() < 0) { // left
		move.set(1, 0);
		row = current->getY();
	} else if (current->getY() < 0) { // up
		move.set(0, 1);
		column = current->getX();
	} else if (current->getX() == this->data.PlaygroundSize) { // right
		move.set(-1, 0);
		row = current->getY();
	} else { // down
		move.set(0, -1);
		column = current->getX();
	}

	for (unsigned int i = 0; i < this->data.Map.size(); i++) {
		Fragment *frag = this->data.Map[i];
		if (frag->getX() == column || frag->getY() == row) {
			current->move(move);
			this->data.Map[i] = current;
			current = frag;
		}
	}
	// current is moving fragment
	this->data.MovingBlock = current;
}

void Game::onMove(Movement mov)
{
	if (this->data.MovingPlayer) {
		Vector2 p = data.OnMove->getPosition();
		if ((p.y() + 1 == data.PlaygroundSize && mov == Movement::Down) ||
				(p.y() == 0 && mov == Movement::Up) ||
				(p.x() == 0 && mov == Movement::Left) ||
				(p.x() + 1 == data.PlaygroundSize && mov == Movement::Right)) {
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
		if (mov == Movement::Right || mov == Movement::Left) {
			int direction = mov == Movement::Right ? 1 : -1;

			if (direction == -1) {
				if (this->movingBlockPosition == this->movingBlockPositions.begin()) {
					this->movingBlockPosition = --this->movingBlockPositions.end();
				} else {
					this->movingBlockPosition--;
				}
			} else {
				if (this->movingBlockPosition == --this->movingBlockPositions.end()) {
					this->movingBlockPosition = this->movingBlockPositions.begin();
				} else {
					this->movingBlockPosition++;
				}
			}
		}

		this->data.MovingBlock->set(this->movingBlockPosition->x(), this->movingBlockPosition->y());
	}
}

void Game::onMoveEnter()
{
	// if block is on the move, switch player
	if (this->data.MovingPlayer) {
		// find currently moving player
		std::vector<Player*>::iterator it = this->data.Players.begin();
		for (; it != this->data.Players.end(); it++) {
			if ((*it) == this->data.OnMove) {
				break;
			}
		}

		if (++it == this->data.Players.end()) {
			this->data.OnMove = this->data.Players.front();
		} else {
			this->data.OnMove = *(it++);
		}
	} else {
		this->pushBlock();
	}

	this->data.MovingPlayer = !this->data.MovingPlayer;
}

void Game::onRotate()
{
	if (!this->data.MovingPlayer) {
		int rotation = static_cast<int>(this->data.MovingBlock->getRotation()) + 1;
		if (rotation > 3) {
			rotation = 0;
		}

		this->data.MovingBlock->rotate(static_cast<FragmentRotation>(rotation));
	}
}

void Game::onGameStart(int players, int size, int cards)
{
	this->data.PlayerCount = players;
	this->data.PlaygroundSize = size;
	this->data.CardCount = cards;
	this->generateMap();
	this->generatePlayers();
	this->data.OnMove = *this->data.Players.begin();
}

void Game::onLoadGame(std::string name) {

}

void Game::onSaveGame() {

}

void Game::onUndo()
{

}

void Game::onRedo()
{

}
