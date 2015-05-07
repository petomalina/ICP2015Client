//
// Created by gelidus on 6.5.2015.
//

#include "LabyrinthItem.h"
#include <algorithm>

LabyrinthItem *LabyrinthItem::rotateLeft()
{
	LabyrinthItem *rotated = new LabyrinthItem(this->Pixels);

	rotated->Pixels[0] = this->Pixels[2];
	rotated->Pixels[1] = this->Pixels[5];
	rotated->Pixels[2] = this->Pixels[8];
	rotated->Pixels[3] = this->Pixels[1];
	rotated->Pixels[5] = this->Pixels[7];
	rotated->Pixels[6] = this->Pixels[0];
	rotated->Pixels[7] = this->Pixels[3];
	rotated->Pixels[8] = this->Pixels[6];

	return rotated;
}

LabyrinthItem *LabyrinthItem::rotateRight()
{
	LabyrinthItem *rotated = new LabyrinthItem(this->Pixels);

	rotated->Pixels[0] = this->Pixels[6];
	rotated->Pixels[1] = this->Pixels[3];
	rotated->Pixels[2] = this->Pixels[0];
	rotated->Pixels[3] = this->Pixels[7];
	rotated->Pixels[5] = this->Pixels[1];
	rotated->Pixels[6] = this->Pixels[8];
	rotated->Pixels[7] = this->Pixels[5];
	rotated->Pixels[8] = this->Pixels[2];

	return rotated;
}

LabyrinthItem *LabyrinthItem::rotateFlip()
{
	LabyrinthItem *rotated = new LabyrinthItem(this->Pixels);

	rotated->Pixels[0] = this->Pixels[8];
	rotated->Pixels[1] = this->Pixels[7];
	rotated->Pixels[2] = this->Pixels[6];
	rotated->Pixels[3] = this->Pixels[5];
	rotated->Pixels[5] = this->Pixels[3];
	rotated->Pixels[6] = this->Pixels[2];
	rotated->Pixels[7] = this->Pixels[1];
	rotated->Pixels[8] = this->Pixels[0];

	return rotated;
}

LabyrinthItem *LabyrinthItem::swapColumns()
{
	LabyrinthItem *swapped = new LabyrinthItem(this->Pixels);
	
	swapped->Pixels[0] = this->Pixels[2];
	swapped->Pixels[2] = this->Pixels[0];
	swapped->Pixels[3] = this->Pixels[5];
	swapped->Pixels[5] = this->Pixels[3];
	swapped->Pixels[6] = this->Pixels[8];
	swapped->Pixels[8] = this->Pixels[6];

	return swapped;
}

LabyrinthItem *LabyrinthItem::swapRows()
{
	LabyrinthItem *swapped = new LabyrinthItem(this->Pixels);

	swapped->Pixels[0] = this->Pixels[6];
	swapped->Pixels[1] = this->Pixels[7];
	swapped->Pixels[2] = this->Pixels[8];
	swapped->Pixels[6] = this->Pixels[0];
	swapped->Pixels[7] = this->Pixels[1];
	swapped->Pixels[8] = this->Pixels[6];


	return swapped;
}


LabyrinthItemL::LabyrinthItemL(): LabyrinthItem(
		std::array<char, 9>{
				'#', ' ', '#',
				'#', ' ', ' ',
				'#', '#', '#'
		}
)
{

}

LabyrinthItemT::LabyrinthItemT(): LabyrinthItem(
		std::array<char, 9>{
				'#', '#', '#',
				' ', ' ', ' ',
				'#', ' ', '#'
		}
)
{

}

LabyrinthItemI::LabyrinthItemI(): LabyrinthItem(
		std::array<char, 9>{
				'#', ' ', '#',
				'#', ' ', '#',
				'#', ' ', '#'
		}
)
{

}
