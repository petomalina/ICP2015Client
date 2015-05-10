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
	this->onGameStart.dispatch(1, 7);
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
		std::string first, second, third;

		// for every column
		for (int j = 0; j < this->game->PlaygroundSize; j++) {
			first += this->blocks[i * this->game->PlaygroundSize + j]->getFirstRow();
			second += this->blocks[i * this->game->PlaygroundSize + j]->getSecondRow();
			third += this->blocks[i * this->game->PlaygroundSize + j]->getThirdRow();
		}
/*
		for (int p = 0; p < this->game->PlayerCount ; ++p) {
			if (this->game->Players[p]){}
		}*/

		rows->push_back(first);
		rows->push_back(second);
		rows->push_back(third);
	}
};

void CLIView::insertPlayerToIndex(char player, int x, int y)
{
	char actual = this->blocks[x + y]->Pixels[4];
	if (actual == ' ')
		this->blocks[x + y]->Pixels[4] = player;
	else
		this->blocks[x + y]->Pixels[4] = calculatePlayer(decodePlayer(actual) + (player - 48));
}

void CLIView::movePlayerFromIndex(char player, int x, int y)
{
	this->blocks[x + y]->Pixels[4] = calculatePlayer(decodePlayer(this->blocks[x + y]->Pixels[4]) - (player - 48));
}

int CLIView::decodePlayer(char pixel)
{
	return pixel - (pixel > 9 ? 55 : 48);
}

char CLIView::calculatePlayer(int player)
{
	return (char) (player + (player > 9 ? 55 : 48));
}


void CLIView::putPlayers()
{


}
