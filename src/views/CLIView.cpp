//
// Created by gelidus on 5.5.2015.
//

#include "CLIView.h"
#include <iostream>

CLIView::CLIView(int size)
{
	this->size = size;
}

void CLIView::initialize()
{
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
	generateMap();
	std::cout << "Here will be Game view\n\n\n";

	std::vector<std::string> mapRows = this->prepareMap();
	for (int i = 0; i < 3 * this->size; ++i) {
		std::cout << mapRows[i] << "\n";
	}
}

void CLIView::clearScreen()
{
	std::cout << std::string(100, '\n');
}

void CLIView::generateMap()
{

	LabyrinthItemFactory f{};

	for (int x = 0; x < size; x++) {
		for (int y = 0; y < size; y++) {
			if (x == 0 && y == 0) {
				this->fragments.push_back(f.L());
			}
			else if (x == 0 && y == size - 1) {
				this->fragments.push_back(f.L()->rotateRight());
			}
			else if (x == size - 1 && y == 0) {
				this->fragments.push_back(f.L()->rotateLeft());
			}
			else if (x == size - 1 && y == size - 1) {
				this->fragments.push_back(f.L()->rotateFlip());
			}
			else if (x % 2 == 0 && y % 2 == 0) {
				// calculate T-s
				if (x == 0) { // up
					this->fragments.push_back(f.T());
				}
				else if (y == 0) { // left
					this->fragments.push_back(f.T()->rotateLeft());
				}
				else if (x == size - 1) { // down
					this->fragments.push_back(f.T()->rotateFlip());
				}
				else if (y == size - 1) { // right
					this->fragments.push_back(f.T()->rotateRight());
				}
				else { // all other (even col/row crossings)
					switch (rand() % 4) { // randomize T rotation
						case 0 :
							this->fragments.push_back(f.T());
							break;
						case 1 :
							this->fragments.push_back(f.T()->rotateRight());
							break;
						case 2 :
							this->fragments.push_back(f.T()->rotateLeft());
							break;
						case 3 :
							this->fragments.push_back(f.T()->rotateFlip());
							break;
						default:
							break;
					}
				}
			}
			else { // all other (odd rows/cols)
				// randomize
				this->fragments.push_back(f.getRandomLabyrinthItem());
			}
		}
	}

	this->movingBlock = f.getRandomLabyrinthItem(); // get one random item that will be used for inserting to maze
}

void CLIView::createMovingBlocks()
{
}

std::vector<std::string> CLIView::prepareMap()
{
	// will prepare map to vector of 3 times <maze-size> strings symbolizing rows of map that will be used to print the maze out.
	std::vector<std::string> mazeRows;
	for (int i = 0; i < 3 * this->size; ++i) {
		mazeRows.push_back("");
	}

	int frags = this->size * this->size;

	for (int i = 0; i < frags; ++i) {
		int row = (i / this->size) * 3;
		mazeRows[row].append(this->fragments[i]->getFirstRow());
		mazeRows[row + 1].append(this->fragments[i]->getSecondRow());
		mazeRows[row + 2].append(this->fragments[i]->getThirdRow());
	}
	return mazeRows;
};
