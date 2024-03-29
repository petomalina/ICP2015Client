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

class Player: public Vector2 {

public:
	const int Index;
	const int Number;
	CardPack Cards;
	bool Moved;

public:
	int points;

public:
	Player(int index, Vector2 position);

	Card &card();

	using Vector2::move;

	void captureCard();

	int getPoints() { return this->points; }

	/**
	 * Draws the new card destroying the current one
	 */
	void drawCard();

	void eraseCard(CardType c);

	/**
	 * Moves the player in the direction
	 * @param type Movement
	 */
	void move(Movement type);
};


#endif //ICP2015CLIENT_PLAYER_H
