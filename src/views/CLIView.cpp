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

	std::cout << "This inicialize the game.\n\n\n";
	//TODO: set values for player/game/..., if not specified (getopt ?) use default.
}

void CLIView::show()
{
	this->showMenu();
}

void CLIView::showMenu()
{
	std::cout << "Welcome to Cli version of MazeICP2015\n\n";
	std::cout << "If you want to start a New game with default settings press <Space> key.\n";
	std::cout << "If you want to edit Settings first press <E> key.\n";

	getchar(); // TODO: delete this

	this->showGame();
}

void CLIView::showGame()
{
	this->clearScreen();
	//TODO: generate map ?
	std::cout << "Here will be Game view\n\n\n";

	std::vector<std::string> mapRows = this->prepareMap();
	for (int i = 0; i < 3 * this->game->PlaygroundSize; ++i) {
		std::cout << mapRows[i] << "\n";
	}
}

void CLIView::clearScreen()
{
	std::cout << std::string(100, '\n');
}

void CLIView::createMovingBlocks()
{
}

std::vector<std::string> CLIView::prepareMap()
{
	// will prepare map to vector of 3 times <maze-size> strings symbolizing rows of map that will be used to print the maze out.
	std::vector<std::string> mazeRows;
	for (int i = 0; i < 3 * this->game->PlaygroundSize; ++i) {
		mazeRows.push_back("");
	}

	int frags = this->game->PlaygroundSize * this->game->PlaygroundSize;

	/*for (int i = 0; i < frags; ++i) {
		int row = (i / this->game->PlaygroundSize) * 3;
		mazeRows[row].append(this->fragments[i]->getFirstRow());
		mazeRows[row + 1].append(this->fragments[i]->getSecondRow());
		mazeRows[row + 2].append(this->fragments[i]->getThirdRow());
	}
	return mazeRows;*/
};
