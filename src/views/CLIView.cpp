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
	std::cout << "If you want to start a New game with default settings press <Space> key.\n";
	std::cout << "If you want to edit Settings first press <E> key.\n";

	getchar(); // TODO: delete this

	// TODO: dispatch correct values
	this->onGameStart.dispatch(4, 7, 12);
	this->reflect(); // reflect fragments to view
	this->showGame();
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
	std::cout << std::string(100, '\n');
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
