//
// Created by gelidus on 14.5.2015.
//

#ifndef ICP2015CLIENT_TREASURE_H
#define ICP2015CLIENT_TREASURE_H

#include "Card.h"
#include "../math/Vector2.h"

class Treasure: public Vector2 {

public:
	const CardType Type;

private:
	Vector2 position;

public:
	Treasure(CardType type, Vector2 pos);

	Vector2 getPosition();
};


#endif //ICP2015CLIENT_TREASURE_H
