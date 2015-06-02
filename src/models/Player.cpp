/**
 * @brief ICP project 2015 (Maze game)
 * @authors xmalin26, xmasek15
 */

#include "Player.h"

Player::Player(int index, Vector2 pos): Vector2(pos), Index(index), Number(std::pow(2, index))
{
	this->Moved = false;
	this->points = 0;
}

Card &Player::card()
{
	return this->Cards.back();
}

void Player::captureCard()
{
	this->points++;
	this->drawCard();
}

void Player::drawCard()
{
	this->Cards.pop_back();
}

void Player::eraseCard(CardType t)
{
	CardPack::iterator it = std::find_if(this->Cards.begin(), this->Cards.end(), [&](Card &c) {
		return c.getType() == t;
	});

	this->Cards.erase(it);
}

void Player::move(Movement type)
{
	switch (type) {
		case Movement::Up:
			this->ry() -= 1;
			break;
		case Movement::Down:
			this->ry() += 1;
			break;
		case Movement::Left:
			this->rx() -= 1;
			break;
		case Movement::Right:
			this->rx() += 1;
			break;
	}
}
