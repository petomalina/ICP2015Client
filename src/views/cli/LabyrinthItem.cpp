//
// Created by gelidus on 6.5.2015.
//

#include "LabyrinthItem.h"

std::array<char, 9> LabyrinthItem::getPixels()
{
	return this->pixels;
}


LabyrinthItem LabyrinthItem::rotateLeft()
{
	// TODO: rotate
	return LabyrinthItem(std::array<char, 9>());
}

LabyrinthItem LabyrinthItem::rotateRight()
{
	// TODO: rotate
	return LabyrinthItem(std::array<char, 9>());
}

LabyrinthItem LabyrinthItem::rotateFlip()
{
	// TODO: rotate
	return LabyrinthItem(std::array<char, 9>());
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
