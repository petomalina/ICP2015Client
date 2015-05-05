//
// Created by gelidus on 5.5.2015.
//

#include "Player.h"

Player::Player(std::string name)
{
	this->name = name;
}

std::string Player::getName() const
{
	return this->name;
}

Card &Player::topCard()
{
	return this->cards.back();
}
