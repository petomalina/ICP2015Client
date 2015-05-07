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
	for (int x = 0; x < size; x++) {
		for (int y = 0; y < size; y++) {

			if (x == 0 && y == 0) {

			} else if (x == 0 && y == size-1) {

			} else if (x == size -1 && y == 0) {

			} else if (x == size -1 && y == size -1) {

			} else if (x % 2 == 0 && y % 2 == 0) {
				// calculate T-s
				if (x == 0) { // up

				} else if (y == 0) { // left

				} else if (x == size -1) { // down

				} else if (y == size -1) { // right

				}

			} else if (x % 2 != 0 && y % 2 != 0) {
				// randomize
			}
		}
	}
}
