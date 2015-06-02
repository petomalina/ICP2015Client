//
// Created by gelidus on 14.5.2015.
//

#ifndef ICP2015CLIENT_TREASURE_H
#define ICP2015CLIENT_TREASURE_H

#include "Card.h"
#include "../math/Vector2.h"

/**
 * Treasure represents each treasure displayed on the map
 */
class Treasure: public Vector2 {

public:
	const CardType Type;

public:
	Treasure(CardType type, Vector2 pos);

};


#endif //ICP2015CLIENT_TREASURE_H
