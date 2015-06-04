/**
 * @brief ICP project 2015 (Maze game)
 * @authors xmalin26, xmasek15
 */

#include "Game.h"

using namespace std::placeholders;

Game::Game(IView *view)
{
	this->view = view;
	this->view->initialize(&this->data);

	this->view->onMove(std::bind(&Game::onMove, this, _1));
	this->view->onMoveEnter(std::bind(&Game::onMoveEnter, this));
	this->view->onRotate(std::bind(&Game::onRotate, this));
	this->view->onGameStart(std::bind(&Game::onGameStart, this, _1, _2, _3, _4));

	this->view->onSave(std::bind(&Game::onSaveGame, this));
	this->view->onLoad(std::bind(&Game::onLoadGame, this, _1));

	this->view->onUndo(std::bind(&Game::onUndo, this));
	this->view->onRedo(std::bind(&Game::onRedo, this));

	this->initGameData();
}

Game::~Game()
{
}

void Game::run()
{
	this->view->show();
}


void Game::clearGameData()
{
	this->data.running = false;
	this->data.initialized = false;

	this->data.Name = "";
	this->data.MovingBlock = nullptr;

	for (Player *plr: this->data.Players) {
		delete plr;
	}
	this->data.OnMove = nullptr;
	this->data.Winner = nullptr;
	this->data.MovingPlayer = false;
	this->data.LockedPosition.set(0, 0);

	this->data.Map.clear();
}

void Game::initGameData()
{
	this->clearGameData();

	this->data.initialized = true;
}

void Game::generateMap()
{
	// clear map before generating
	this->data.Map.clear();

	if (this->data.MovingBlock != nullptr) {
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
	this->generateMovingBlockPositions();
}


void Game::generateMovingBlockPositions()
{
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

void Game::generateTreasures()
{
	int i = this->data.CardCount;
	do {
		int x = rand() % this->data.PlaygroundSize;
		int y = rand() % this->data.PlaygroundSize;

		if (x == 0 || y == 0 || x == this->data.PlaygroundSize -1 || y == this->data.PlaygroundSize -1) {
			continue;
		}

		auto occupied = std::find_if(this->data.Treasures.begin(), this->data.Treasures.end(), [&] (Treasure& t) {
			return t == Vector2{x, y};
		});

		if (occupied != this->data.Treasures.end()) {
			continue;
		}

		this->data.Treasures.push_back(Treasure{static_cast<CardType>(i), Vector2{x, y}});

		i--;
	} while(i > 0);
}

void Game::loadGame(std::string name)
{
	this->data.initialized = false;

	std::string savePath = "examples/" + name + ".save";
	std::ifstream saveFile{savePath};
	if (saveFile.fail()) {
		return; // cant load game
	}

	saveFile >> this->data.PlaygroundSize >> this->data.CardCount >> this->data.MovingPlayer;
	this->data.Map.clear();

	int x, y, type, rotation;
	for (int i = 0; i < this->data.PlaygroundSize * this->data.PlaygroundSize; i++) {
		saveFile >> x >> y >> type >> rotation;
		auto frag = FragmentFactory::create(x, y, static_cast<FragmentType>(type), static_cast<FragmentRotation>(rotation));
		this->data.Map.push_back(frag);
	}
	// moving fragment
	saveFile >> x >> y >> type >> rotation;
	this->data.MovingBlock = FragmentFactory::create(x, y, static_cast<FragmentType>(type), static_cast<FragmentRotation>(rotation));

	// player counts
	int playerOnMove;
	saveFile >> this->data.PlayerCount >> playerOnMove;
	// clear
	for (Player *plr : this->data.Players) {
		delete plr;
	}
	this->data.Players.clear();

	for (int i = 0; i < this->data.PlayerCount; i++) {
		int index, number, cards;
		saveFile >> number >> index >> x >> y >> cards;
		Player *plr = new Player(index, Vector2{x, y});
		this->data.Players.push_back(plr);

		for (int c = 0; c < cards; c++) {
			int card;
			saveFile >> card;
			plr->Cards.push_back(static_cast<CardType>(card));
		}

		plr->points = static_cast<int>(this->data.CardCount - plr->Cards.size());
	}

	int treasures;
	saveFile >> treasures;
	for (int i = 0; i < treasures; i++) {
		int cardType, tx, ty;
		saveFile >> tx >> ty >> cardType;
		this->data.Treasures.push_back(Treasure{static_cast<CardType>(cardType), Vector2{tx, ty}});
	}

	this->data.OnMove = this->data.Players[playerOnMove];
	this->generateMovingBlockPositions();

	saveFile.close();
	this->data.initialized = true;
}

void Game::saveGame()
{
	if (!this->data.running) {
		return;
	}

	std::string savePath = "examples/" + this->data.Name + ".save";
	std::ofstream saveFile{savePath};

	// stream in
	saveFile << this->data.PlaygroundSize << " " << this->data.CardCount << " " << this->data.MovingPlayer << "\n";
	for (auto frag: this->data.Map) {
		saveFile << frag->x() << " " << frag->y() << " " << static_cast<int>(frag->Type) << " " << static_cast<int>(frag->getRotation()) << "\n";
	}

	auto frag = this->data.MovingBlock;
	saveFile << frag->x() << " " << frag->y() << " " << static_cast<int>(frag->Type) << " " << static_cast<int>(frag->getRotation()) << "\n";

	saveFile << this->data.PlayerCount << " " << this->data.OnMove->Index << "\n";
	for (Player *plr: this->data.Players) {
		saveFile << plr->Number << " " << plr->Index << " " << plr->x() << " " << plr->y() << " " << plr->Cards.size() << " ";
		for (Card &c : plr->Cards) {
			saveFile << static_cast<int>(c.getType()) << " ";
		}
		saveFile << "\n";
	}

	saveFile << this->data.Treasures.size() << "\n";
	for (Treasure &t: this->data.Treasures) {
		saveFile << t.x() << " " << t.y() << " " << static_cast<int>(t.Type) << "\n";
	}

	saveFile.close();
}

bool Game::pushBlock()
{
	// calculation of movement
	auto movingBlock = this->data.MovingBlock;

	if (*movingBlock == this->data.LockedPosition) {
		return false;
	}

	Vector2 move{0, 0};
	int row = -1, column = -1;

	if (movingBlock->getX() < 0) { // left
		move.set(1, 0);
		row = movingBlock->getY();
	} else if (movingBlock->getY() < 0) { // up
		move.set(0, 1);
		column = movingBlock->getX();
	} else if (movingBlock->getX() == this->data.PlaygroundSize) { // right
		move.set(-1, 0);
		row = movingBlock->getY();
	} else { // down
		move.set(0, -1);
		column = movingBlock->getX();
	}

	// fragment movements
	if (move.x() > 0 || move.y() > 0) {
		int fragIndex = 0;
		std::shared_ptr<Fragment> mov = nullptr;

		for (unsigned long i = 0; i < this->data.Map.size(); ++i) {
			auto frag = this->data.Map[i];
			if (frag->getX() == column || frag->getY() == row) {
				this->movePlayersOnFragment(frag, move);
				fragIndex++;

				frag->move(move);
				this->data.Map[i] = mov;

				if (fragIndex == 1) {
					this->data.Map[i] = movingBlock;
					movingBlock->move(move);
				}
				else if (fragIndex == data.PlaygroundSize) {
					this->data.MovingBlock = frag;
				}

				mov = frag;
			}
		}
	} else {
		int fragIndex = 0;
		std::shared_ptr<Fragment> mov = nullptr;

		for (unsigned long i = this->data.Map.size() -1; i > 0; --i) {
			auto frag = this->data.Map[i];
			if (frag->getX() == column || frag->getY() == row) {
				this->movePlayersOnFragment(frag, move);
				fragIndex++;

				frag->move(move);
				this->data.Map[i] = mov;

				if (fragIndex == data.PlaygroundSize) {
					this->data.MovingBlock = frag;
				}
				else if (fragIndex == 1) {
					this->data.Map[i] = movingBlock;
					movingBlock->move(move);
				}

				mov = frag;
			}
		}
	}

	this->data.LockedPosition.set(this->data.MovingBlock->x(), this->data.MovingBlock->y());

	// correction of iterator
	for (std::vector<Vector2>::iterator it = this->movingBlockPositions.begin(); it != this->movingBlockPositions.end(); it++) {
		if (*this->data.MovingBlock == *it) {
			this->movingBlockPosition = it;
		}
	}

	for (Player *p : this->data.Players) {
		p->Moved = false; // reset
	}

	return true;
}

void Game::onMove(Movement mov)
{
	if (this->data.MovingPlayer) {
		Player &p = *this->data.OnMove;
		if ((p.y() + 1 == data.PlaygroundSize && mov == Movement::Down) ||
				(p.y() == 0 && mov == Movement::Up) ||
				(p.x() == 0 && mov == Movement::Left) ||
				(p.x() + 1 == data.PlaygroundSize && mov == Movement::Right)) {
			return;
		}

		// next fragment calculation
		std::shared_ptr<Fragment> nextFragment = nullptr, thisFragment = this->data.Map[this->data.PlaygroundSize * p.y() + p.x()];
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

	this->calculateCollisions();
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
		if (!this->pushBlock()) {
			return; // skip collisions and moving when push was rejected
		}
	}

	this->data.MovingPlayer = !this->data.MovingPlayer;
	this->calculateCollisions();
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

void Game::onGameStart(std::string name, int players, int size, int cards)
{
	if (name == "") {
		name = "NewGame";
	}

	this->data.Name = name;
	this->data.PlayerCount = players;
	this->data.PlaygroundSize = size;
	this->data.CardCount = cards;
	this->generateMap();
	this->generatePlayers();
	this->generateTreasures();
	this->data.OnMove = *this->data.Players.begin();
	this->data.running = true;
}

void Game::onLoadGame(std::string name) {
	this->loadGame(name);
}

void Game::onSaveGame() {
	this->saveGame();
}

void Game::onUndo()
{

}

void Game::onRedo()
{

}

void Game::movePlayersOnFragment(std::shared_ptr<Fragment> frag, Vector2 &mov)
{
	for (Player *p : this->data.Players) {
		if (!p->Moved && *p == *frag) {
			p->move(mov);
			if (p->x() < 0) {
				p->rx() = this->data.PlaygroundSize-1;
			} else if (p->x() >= this->data.PlaygroundSize) {
				p->rx() = 0;
			} else if (p->y() < 0) {
				p->ry() = this->data.PlaygroundSize-1;
			} else if (p->ry() >= this->data.PlaygroundSize) {
				p->ry() = 0;
			}

			p->Moved = true;
		}
	}
}

void Game::calculateCollisions() {
	for (Player *p: this->data.Players) {
		std::vector<Treasure>::iterator tr = std::find_if(this->data.Treasures.begin(), this->data.Treasures.end(), [&](Treasure &t) {
			return p->card().getType() == t.Type && *p == t;
		});

		if (tr != this->data.Treasures.end()) {
			CardType type = p->card().getType();
			p->captureCard(); // adds points and draws new

			for (Player *er: this->data.Players) {
				er->eraseCard(type);
			}

			// remove from treasures on map
			this->data.Treasures.erase(tr);
		}
	}

	this->calculateMatchEndingConditions();
}

void Game::calculateMatchEndingConditions()
{
	int winCondition = this->data.CardCount / this->data.PlayerCount;

	for (Player *p: this->data.Players) {
		if (p->getPoints() >= winCondition) {
			this->data.Winner = p;
			break;
		}
	}
}
