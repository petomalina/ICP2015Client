//
// Created by gelidus on 5.5.2015.
//

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

	for (Fragment *frag : this->game->Map) {
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

	bool cond = false;
	do {
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

	/*
	bool cond=false;
	do {
		switch (pressed) {
			case KeyBindings::keySpace:
				//do smtng
				break;
			default:
				cond = true;
		}
	} while (cond);*/


/*
    // T ODO: dispatch correct values
	this->onGameStart.dispatch(4, 7);
	this->reflect(); // reflect fragments to view
	this->showGame();
 */

}

void CLIView::showOptions()
{
	this->clearScreen();
	std::cout << "Current game settings:\n\n";
	std::cout << (this->game->Name == "" ? "\t" : "\tGame: " + std::string(this->game->Name) + " | ") +
				 "Players: " << this->game->PlayerCount << " | Maze size: " << this->game->PlaygroundSize << "\n\n";
	std::cout << "\tSelect action:\n";
	std::cout << "\t\t1 - Set players\n";
	std::cout << "\t\t2 - Set maze size\n";
	std::cout << "\t\t3 - Set game name\n";
	std::cout << "\t\t4 - Return\n";
	std::cout << "\t\t5 - Start Game\n\n";


	bool cond = false;
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
				this->showMenu();
				break;
			case KeyBindings::key5:
				// TODO: dispatch correct values
				this->onGameStart.dispatch(this->game->PlayerCount, this->game->PlaygroundSize);
				this->reflect(); // reflect fragments to view
				this->showGame();
			default:
				cond = true;
		}
	} while (cond);

	std::vector<std::string> map;
	this->prepareMap(&map);

	for (std::string row : map) {
		std::cout << row << std::endl;
	}
}

void CLIView::showLoadDialog()
{
	// TODO: loading
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
	this->c5learScreen();

	std::cout << "Enter size of the maze:\n\n";
	std::cout << "\t\t1 - Set size to 5\n";
	std::cout << "\t\t2 - Set size to 7\n";
	std::cout << "\t\t3 - Set size to 9\n";
	std::cout << "\t\t4 - Set size to 11\n";

	int size = 7;

	bool cond = false;
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
	this->clearScreen();
	std::cout << "Here will be Game view\n\n\n";

	std::vector<std::string> map;
	this->prepareMap(&map);

	for (std::string row : map) {
		std::cout << row << std::endl;
	}
}

void CLIView::clearScreen()
{
	std::cout << std::string(50, '\n');
}

void CLIView::createMovingBlocks()
{
}

void CLIView::prepareMap(std::vector<std::string> *rows)
{
	// for every row
	for (int i = 0; i < this->game->PlaygroundSize; i++) {
		std::string first, second, third, second_row;

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
			second += second_row;
			third += this->blocks[i * this->game->PlaygroundSize + j]->getThirdRow();
		}

		rows->push_back(first);
		rows->push_back(second);
		rows->push_back(third);
	}
};

char CLIView::insertPlayer(int player, char field)
{
	return field == ' ' ? (char) (player + '0') : calculatePlayer(decodePlayer(field) + (player - '0'));
}

void CLIView::movePlayerFromIndex(char player, int x, int y)
{
	this->blocks[x + y]->Pixels[4] = calculatePlayer(decodePlayer(this->blocks[x + y]->Pixels[4]) - (player - '0'));
}

int CLIView::decodePlayer(char pixel)
{
	return pixel - (pixel > 9 ? 55 : '0'); //55 is 'A' - 10 (numeric values)
}

char CLIView::calculatePlayer(int player)
{
	return (char) (player + (player > 9 ? 55 : '0')); //55 is 'A' - 10 (numeric values)
}

char CLIView::ourGetCh()
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
	return (char) ch; /*return received char */
#else
	return getchar();
#endif
}