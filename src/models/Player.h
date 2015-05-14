/**
 * @brief ICP project 2015 (Maze game)
 * @authors xmalin26, xmasek15
 */

#ifndef ICP2015CLIENT_PLAYER_H
#define ICP2015CLIENT_PLAYER_H

#include <string>
#include <QtCore/QPoint>

#include "../math/Vector2.h"
#include "Card.h"

enum class Movement {
	Up, Down, Left, Right
};

class Player {

public:
	const int Index;
	const int Number;
	CardPack Cards;

private:
	Vector2 position;

public:
	Player(int index, Vector2 position);

	Vector2 &getPosition() { return this->position; }

	Card &card();

	/**
	 * Draws the new card destroying the current one
	 */
	void drawCard();

	/**
	 * Moves the player in the direction
	 * @param type Movement
	 */
	void move(Movement type);
};


#endif //ICP2015CLIENT_PLAYER_H
