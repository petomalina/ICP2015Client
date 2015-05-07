//
// Created by gelidus on 5.5.2015.
//

#include "CLIView.h"


CLIView::CLIView(int size)
{
	this->size = size;
}

void CLIView::initialize()
{

}

void CLIView::show()
{

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
					this->fragments.push_back(f.T()->rotateRight());
				}
				else if (x == size - 1) { // down
					this->fragments.push_back(f.T()->rotateLeft());
				}
				else if (y == size - 1) { // right
					this->fragments.push_back(f.T()->rotateFlip());
				}

			}
			else if (x % 2 != 0 && y % 2 != 0) {
				// randomize
				switch (rand() % 12) {
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
					case 4 :
						this->fragments.push_back(f.L());
						break;
					case 5 :
						this->fragments.push_back(f.L()->rotateRight());
						break;
					case 6 :
						this->fragments.push_back(f.L()->rotateLeft());
						break;
					case 7 :
						this->fragments.push_back(f.L()->rotateFlip());
						break;
					case 8 :
						this->fragments.push_back(f.I());
						break;
					case 9 :
						this->fragments.push_back(f.I()->rotateRight());
						break;
					case 10 :
						this->fragments.push_back(f.I()->rotateLeft());
						break;
					case 11 :
						this->fragments.push_back(f.I()->rotateFlip());
						break;
					default:
						break;
				}
				this->fragments.push_back(f.T()->rotateFlip());
			}
		}
	}
}
