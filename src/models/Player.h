//
// Created by gelidus on 5.5.2015.
//

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

	void drawCard();

	void move(Movement type);
};


#endif //ICP2015CLIENT_PLAYER_H
