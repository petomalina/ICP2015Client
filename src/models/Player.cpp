//
// Created by gelidus on 5.5.2015.
//

#include "Player.h"

Player::Player(int index, QPoint pos): Index(index-1), Number(std::pow(index, 2))
{
	this->position = pos;
}

Card &Player::card()
{
	return this->Cards.back();
}

void Player::drawCard()
{
	this->Cards.pop_back();
}

void Player::move(Movement type)
{
	switch (type) {
		case Movement::Up:
			this->position.ry() -= 1;
			break;
		case Movement::Down:
			this->position.ry() += 1;
			break;
		case Movement::Left:
			this->position.rx() -= 1;
			break;
		case Movement::Right:
			this->position.rx() += 1;
			break;
	}
}
