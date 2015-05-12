/**
 * @brief ICP project 2015 (Maze game)
 * @authors xmalin26, xmasek15
 */


#include "Card.h"

Card::Card(CardType type)
{
	this->type = type;
}

CardType Card::getType()
{
	return this->type;
}
