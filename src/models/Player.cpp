/**
 * @brief ICP project 2015 (Maze game)
 * @authors xmalin26, xmasek15
 */

#include "Player.h"

Player::Player(int index, Vector2 pos): Index(index), Number(std::pow(2, index))
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
