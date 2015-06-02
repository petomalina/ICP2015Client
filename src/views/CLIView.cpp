/**
 * @brief ICP project 2015 (Maze game)
 * @authors xmalin26, xmasek15
 */


#include "CLIView.h"
#include <iostream>

CLIView::CLIView()
{
}

void CLIView::initialize(GameData *data)
{
	this->game = data;

	std::cout << "This initializes the game.\n\n\n";
}

void CLIView::show()
{
	this->showMenu();
}

void CLIView::reflect()
{
	for (CLIBlock *block : this->blocks) {
		delete block;
	}
	this->blocks.clear();

	for (auto frag : this->game->Map) {
		this->blocks.push_back(new CLIBlock(frag));
	}
}

void CLIView::showMenu()
{
	std::cout << "Welcome to Cli version of MazeICP2015\n\n";
	std::cout << "\tSelect action:\n";
	std::cout << "\t\t1 - Start new game\n";
	std::cout << "\t\t2 - Load game\n";
	std::cout << "\t\t3 - Exit game\n";

	this->game->PlayerCount = 4; // setting default game values
	this->game->PlaygroundSize = 7;
	this->game->CardCount = 12;

	bool cond;
	do {
		cond = false;
		KeyBindings pressed = static_cast<KeyBindings >(ourGetCh());
		switch (pressed) {
			case KeyBindings::key1:
				this->showOptions();
				break;
			case KeyBindings::key2:
				this->showLoadDialog();
				break;
			case KeyBindings::key3:
				exit(0);
			default:
				cond = true;
		}
	} while (cond);

}

void CLIView::showOptions()
{
	this->clearScreen();
	std::cout << "Current game settings:\n\n";
	std::cout << (this->game->Name == "" ? "\t" : "\tGame: " + std::string(this->game->Name) + " | ") +
				 "Players: " << this->game->PlayerCount <<
	" | Maze size: " << this->game->PlaygroundSize << " | Cards: " << this->game->CardCount << "\n\n";

	std::cout << "\tSelect action:\n";
	std::cout << "\t\t1 - Set players\n";
	std::cout << "\t\t2 - Set maze size\n";
	std::cout << "\t\t3 - Set game name\n";
	std::cout << "\t\t4 - Set how many threasures\n";
	std::cout << "\t\t5 - Return\n";
	std::cout << "\t\t6 - Start Game\n\n";


	bool cond;
	do {
		cond = false;
		KeyBindings pressed = static_cast<KeyBindings>(ourGetCh());
		switch (pressed) {
			case KeyBindings::key1:
				this->showSetPlayers();
				break;
			case KeyBindings::key2:
				this->showSetSize();
				break;
			case KeyBindings::key3:
				this->showSetGameName();
				break;
			case KeyBindings::key4:
				this->game->CardCount = (this->game->CardCount == 12 ? 24 : 12);
				this->showOptions();
				break;
			case KeyBindings::key5:
				this->showMenu();
				break;
			case KeyBindings::key6:
				this->onGameStart.dispatch(this->game->PlayerCount, this->game->PlaygroundSize, this->game->CardCount);
				this->reflect(); // reflect fragments to view
				this->showGame();
			default:
				cond = true;
		}
	} while (cond);
}

void CLIView::showLoadDialog()
{
	std::cout << "Enter the name of the save to Load:\n";
	std::cout << "(use format without extension [example: mysavegame42])\n\n\n";
	std::string gameName;
	std::cin >> gameName;
	gameName.resize(128);
	gameName.shrink_to_fit();

	//TODO: load game


	//after correct loading run game
	this->showGame();
}

void CLIView::showSetGameName()
{
	std::cout << "Enter the name of this game:\n";
	std::cout << "(use 32 basic chars)\n\n\n";
	std::string gameName;
	std::cin >> gameName;
	gameName.resize(32);
	gameName.shrink_to_fit();
	this->game->Name = gameName;
	this->showOptions();
}

void CLIView::showSetPlayers()
{
	std::cout << "Enter number of players:\n\n";
	int players;
	KeyBindings pressed = static_cast<KeyBindings>(ourGetCh());

	switch (pressed) {
		case KeyBindings::key1:
			players = 1;
			break;
		case KeyBindings::key2:
			players = 2;
			break;
		case KeyBindings::key3:
			players = 3;
			break;
		default:
			players = 4;
	}

	this->game->PlayerCount = players;
	this->showOptions();
}

void CLIView::showSetSize()
{
	this->clearScreen();

	std::cout << "Enter size of the maze:\n\n";
	std::cout << "\t\t1 - Set size to 5\n";
	std::cout << "\t\t2 - Set size to 7\n";
	std::cout << "\t\t3 - Set size to 9\n";
	std::cout << "\t\t4 - Set size to 11\n";

	int size = 7;

	bool cond;
	do {
		cond = false;
		KeyBindings pressed = static_cast<KeyBindings>(ourGetCh());
		switch (pressed) {
			case KeyBindings::key1:
				size = 5;
				break;
			case KeyBindings::key2:
				size = 7;
				break;
			case KeyBindings::key3:
				size = 9;
				break;
			case KeyBindings::key4:
				size = 11;
				break;
			default:
				cond = true;
				break;
		}
	} while (cond);

	this->game->PlaygroundSize = size;
	this->showOptions();
}

void CLIView::showGame()
{
	bool renew = true;
	do {
		if (renew) {
			this->reflect();
			this->showGameMap(); //displays the game view
		}


		KeyBindings pressed = static_cast<KeyBindings>(ourGetCh());
		switch (pressed) {
			case KeyBindings::keyW:
				this->onMove(Movement::Up);
				renew = true;
				break;
			case KeyBindings::keyS:
				this->onMove(Movement::Down);
				renew = true;
				break;
			case KeyBindings::keyA:
				this->onMove(Movement::Left);
				renew = true;
				break;
			case KeyBindings::keyD:
				this->onMove(Movement::Right);
				renew = true;
				break;
			case KeyBindings::keyR:
				this->onRotate();
				renew = true;
				break;
			case KeyBindings::keySpace:
				this->onMoveEnter();
				renew = true;
				break;
			case KeyBindings::keyZ:
				//TODO: UNDO
				renew = true;
				break;
			case KeyBindings::keyX:
				//TODO: REDO
				renew = true;
				break;
			case KeyBindings::keyK:
				std::cout << "Game saved.\n";
				this->onSave();
				renew = false;
				break;
			case KeyBindings::keyL:
				this->onLoad(this->game->Name);
				renew = true;
				break;
			case KeyBindings::keyT:
				exit(0);
			default:
				renew = false;
		}
	} while (true);

}

void CLIView::showGameMap()
{
	this->clearScreen();

	std::cout << "\tMovement: W, A, S, D keyboard keys\n";
	std::cout << "\tActions: Space - end turn\n";
	std::cout << "\t         R     - rotate block\n";
	std::cout << "\t         L     - load game\n";
	std::cout << "\t         K     - save game\n";
	std::cout << "\t         T     - exit game\n";
	std::cout << "\n\n";

	std::vector<std::string> map;
	this->prepareMap(&map);

	// print map to stdout
	for (std::string row : map) {
		std::cout << row << std::endl;
	}
}

void CLIView::clearScreen()
{
	std::cout << std::string(50, '\n');
}

void CLIView::prepareMap(std::vector<std::string> *rows)
{
	CLIBlock *movingBlock = new CLIBlock(this->game->MovingBlock);
	movingBlock->rotate(this->game->MovingBlock->getRotation());

	FragmentFactory *factory = new FragmentFactory();
	CLIBlock *emptyBlock = new CLIBlock(factory->create(-1, -1, FragmentType::N));

	prepareFirstLastRow(rows, movingBlock, emptyBlock, -1);
/*
	for (int t = 0; t < this->game->CardCount; ++t) {
		auto treasure = this->game->Treasures[t];
		std::cout << insertTreasure(treasure.Type) << " suradnice: " << treasure.x() << "\t" << treasure.y() << std::endl;
	}
*/
	// for every row
	for (int i = 0; i < this->game->PlaygroundSize; i++) {
		std::string first, second, third, second_row;

		prepareFirstLastCol(&first, &second, &third, movingBlock, emptyBlock, -1, i);

		// for every column
		for (int j = 0; j < this->game->PlaygroundSize; j++) {
			first += this->blocks[i * this->game->PlaygroundSize + j]->getFirstRow();
			second_row = this->blocks[i * this->game->PlaygroundSize + j]->getSecondRow();
			for (int p = 0; p < this->game->PlayerCount; ++p) {
				auto player = this->game->Players[p];
				auto playerPosition = player->getPosition();
				if (playerPosition.y() == i && playerPosition.x() == j)
					second_row[2] = this->insertPlayer(player->Number, second_row[2]);
			}

			for (int t = 0; t < this->game->CardCount; ++t) {
				auto treasure = this->game->Treasures[t];
				if (treasure.y() == i && treasure.x() == j)
					second_row[2] = this->insertTreasure(treasure.Type);
			}

			second += second_row;
			third += this->blocks[i * this->game->PlaygroundSize + j]->getThirdRow();
		}

		prepareFirstLastCol(&first, &second, &third, movingBlock, emptyBlock, this->game->PlaygroundSize, i);

		rows->push_back(first);
		rows->push_back(second);
		rows->push_back(third);
	}

	prepareFirstLastRow(rows, movingBlock, emptyBlock, this->game->PlaygroundSize);
}

void CLIView::prepareFirstLastRow(std::vector<std::string> *rows, CLIBlock *moving, CLIBlock *empty, int index)
{
	std::string first, second, third;
	for (int j = 0; j < this->game->PlaygroundSize + 2; j++) {
		if (this->game->MovingBlock->getY() == index && this->game->MovingBlock->getX() + 1 == j) {
			first += moving->getFirstRow();
			second += moving->getSecondRow();
			third += moving->getThirdRow();
		}
		else {
			first += empty->getFirstRow();
			second += empty->getSecondRow();
			third += empty->getThirdRow();
		}
	}
	rows->push_back(first);
	rows->push_back(second);
	rows->push_back(third);
}

void CLIView::prepareFirstLastCol(std::string *first, std::string *second, std::string *third, CLIBlock *moving,
								  CLIBlock *empty, int index, int row)
{
	if (this->game->MovingBlock->getY() == row && this->game->MovingBlock->getX() == index) {
		*first += moving->getFirstRow();
		*second += moving->getSecondRow();
		*third += moving->getThirdRow();
	}
	else {
		*first += empty->getFirstRow();
		*second += empty->getSecondRow();
		*third += empty->getThirdRow();
	}
}

char CLIView::insertPlayer(int player, char field)
{
	return field == ' ' ? (char) (player + '0') : calculatePlayer(decodePlayer(field) + player);
}

char CLIView::insertTreasure(CardType type)
{
	return static_cast<char>(type) + 'A';
}

int CLIView::decodePlayer(char pixel)
{
	return pixel - (pixel > '9' ? 55 : '0'); //55 is 'A' - 10 (numeric values)
}

char CLIView::calculatePlayer(int player)
{
	return (char) (player + (player > 9 ? 55 : '0')); //55 is 'A' - 10 (numeric values)
}

int CLIView::ourGetCh()
{
#if __linux__
	int ch;
	struct termios oldT;
	struct termios newT;
	tcgetattr(STDIN_FILENO, &oldT); /*store old settings */
	newT = oldT; /* copy old settings to new settings */
	newT.c_lflag &= ~(ICANON | ECHO); /* make one change to old settings in new settings */
	tcsetattr(STDIN_FILENO, TCSANOW, &newT); /*apply the new settings immediately */
	ch = getchar(); /* standard getchar call */
	tcsetattr(STDIN_FILENO, TCSANOW, &oldT); /*reapply the old settings */
	return ch; /*return received char (as int) */
#else
	return getchar();
#endif
}

