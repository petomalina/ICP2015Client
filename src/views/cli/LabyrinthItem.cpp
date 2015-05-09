//
// Created by gelidus on 6.5.2015.
//

#include "LabyrinthItem.h"
#include <algorithm>

#include <iostream>


LabyrinthItem *LabyrinthItem::rotateLeft()
{
	std::array<char, 9> rotated = this->Pixels;

	rotated[0] = this->Pixels[2];
	rotated[1] = this->Pixels[5];
	rotated[2] = this->Pixels[8];
	rotated[3] = this->Pixels[1];
	rotated[5] = this->Pixels[7];
	rotated[6] = this->Pixels[0];
	rotated[7] = this->Pixels[3];
	rotated[8] = this->Pixels[6];

	this->Pixels = rotated;
	return this;
}

LabyrinthItem *LabyrinthItem::rotateRight()
{
	std::array<char, 9> rotated = this->Pixels;

	rotated[0] = this->Pixels[6];
	rotated[1] = this->Pixels[3];
	rotated[2] = this->Pixels[0];
	rotated[3] = this->Pixels[7];
	rotated[5] = this->Pixels[1];
	rotated[6] = this->Pixels[8];
	rotated[7] = this->Pixels[5];
	rotated[8] = this->Pixels[2];

	this->Pixels = rotated;
	return this;
}

LabyrinthItem *LabyrinthItem::rotateFlip()
{
	std::array<char, 9> rotated = this->Pixels;

	rotated[0] = this->Pixels[8];
	rotated[1] = this->Pixels[7];
	rotated[2] = this->Pixels[6];
	rotated[3] = this->Pixels[5];
	rotated[5] = this->Pixels[3];
	rotated[6] = this->Pixels[2];
	rotated[7] = this->Pixels[1];
	rotated[8] = this->Pixels[0];

	this->Pixels = rotated;
	return this;
}

LabyrinthItem *LabyrinthItemFactory::L()
{
	new LabyrinthItem{{
							  '#', '#', '#',
							  '#', ' ', ' ',
							  '#', ' ', '#',
					  }
	};
}

LabyrinthItem *LabyrinthItemFactory::T()
{
	return
			new LabyrinthItem{{
									  '#', '#', '#',
									  ' ', ' ', ' ',
									  '#', ' ', '#',
							  }
			};
}

LabyrinthItem *LabyrinthItemFactory::I()
{
	return
			new LabyrinthItem{{
									  '#', ' ', '#',
									  '#', ' ', '#',
									  '#', ' ', '#',
							  }
			};
}

LabyrinthItem *LabyrinthItemFactory::getRandomLabyrinthItem()
{
	switch (rand() % 12) {
		case 0 :
			return LabyrinthItemFactory::T();
		case 1 :
			return LabyrinthItemFactory::T()->rotateRight();
		case 2 :
			return LabyrinthItemFactory::T()->rotateLeft();
		case 3 :
			return LabyrinthItemFactory::T()->rotateFlip();
		case 4 :
			return LabyrinthItemFactory::L();
		case 5 :
			return LabyrinthItemFactory::L()->rotateRight();
		case 6 :
			return LabyrinthItemFactory::L()->rotateLeft();
		case 7 :
			return LabyrinthItemFactory::L()->rotateFlip();
		case 8 :
			return LabyrinthItemFactory::I();
		case 9 :
			return LabyrinthItemFactory::I()->rotateRight();
		case 10 :
			return LabyrinthItemFactory::I()->rotateLeft();
		case 11 :
			return LabyrinthItemFactory::I()->rotateFlip();
		default:
			return LabyrinthItemFactory::T(); // catchup
	}
}

std::string LabyrinthItem::str()
{
	return std::string(this->Pixels.begin(), this->Pixels.end());
}

std::string LabyrinthItem::getFirstRow()
{
	return std::string() + this->Pixels[0] + " " + this->Pixels[1] + " " + this->Pixels[2] + " ";
}

std::string LabyrinthItem::getSecondRow()
{
	return std::string() + this->Pixels[3] + " " + this->Pixels[4] + " " + this->Pixels[5] + " ";
}

std::string LabyrinthItem::getThirdRow()
{
	return std::string() + this->Pixels[6] + " " + this->Pixels[7] + " " + this->Pixels[8] + " ";
}
