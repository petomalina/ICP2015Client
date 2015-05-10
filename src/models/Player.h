//
// Created by gelidus on 5.5.2015.
//

#ifndef ICP2015CLIENT_PLAYER_H
#define ICP2015CLIENT_PLAYER_H

#include <string>
#include <QtCore/QPoint>

#include "Card.h"

enum class Movement {
	Up, Down, Left, Right
};

class Player {

public:
	const int Number;
	CardPack Cards;

private:
	QPoint position;

public:
	Player(int number, QPoint position);

	QPoint getPosition() const { return this->position; }

	Card &card();

	void drawCard();

	void move(Movement type);
};


#endif //ICP2015CLIENT_PLAYER_H
