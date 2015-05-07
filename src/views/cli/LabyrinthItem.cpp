//
// Created by gelidus on 6.5.2015.
//

#include "LabyrinthItem.h"
#include <algorithm>

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

LabyrinthItem *LabyrinthItem::swapColumns()
{
	std::array<char, 9> swapped = this->Pixels;

	swapped[0] = this->Pixels[2];
	swapped[2] = this->Pixels[0];
	swapped[3] = this->Pixels[5];
	swapped[5] = this->Pixels[3];
	swapped[6] = this->Pixels[8];
	swapped[8] = this->Pixels[6];

	this->Pixels = swapped;
	return this;
}

LabyrinthItem *LabyrinthItem::swapRows()
{
	std::array<char, 9> swapped = this->Pixels;

	swapped[0] = this->Pixels[6];
	swapped[1] = this->Pixels[7];
	swapped[2] = this->Pixels[8];
	swapped[6] = this->Pixels[0];
	swapped[7] = this->Pixels[1];
	swapped[8] = this->Pixels[6];


	this->Pixels = swapped;
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
