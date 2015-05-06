//
// Created by gelidus on 6.5.2015.
//

#include "LabyrinthItem.h"

LabyrinthItem *LabyrinthItem::rotateLeft()
{
	LabyrinthItem *rotated = new LabyrinthItem();
	// TODO: rotate

	return rotated;
}

LabyrinthItem *LabyrinthItem::rotateRight()
{
	LabyrinthItem *rotated = new LabyrinthItem();
	// TODO: rotate

	return rotated;
}

LabyrinthItem *LabyrinthItem::rotateFlip()
{
	LabyrinthItem *rotated = new LabyrinthItem();
	// TODO: rotate

	return rotated;
}

LabyrinthItemL::LabyrinthItemL() : LabyrinthItem(
		std::array<char, 9>{
				'#', ' ', '#',
				'#', ' ', ' ',
				'#', '#', '#'
		}
)
{

}
