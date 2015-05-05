//
// Created by gelidus on 5.5.2015.
//

#include "Card.h"

Card::Card(CardType type)
{
	this->type = type;
}

CardType Card::getType()
{
	return this->type;
}
