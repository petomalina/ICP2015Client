/**
 * @brief ICP project 2015 (Maze game)
 * @authors xmalin26, xmasek15
 */

#include "CardPackGenerator.h"
#include <algorithm>

CardPackGenerator::CardPackGenerator(int size)
{
	this->size = size;
}

void CardPackGenerator::generatePack(CardPack &pack)
{
	for (int i = 1; i < size + 1; i++) {
		pack.push_back(static_cast<CardType>(i));
	}

	random_shuffle(std::begin(pack), std::end(pack));
}
