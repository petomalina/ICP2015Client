//
// Created by gelidus on 5.5.2015.
//

#ifndef ICP2015CLIENT_PLAYER_H
#define ICP2015CLIENT_PLAYER_H

#include <string>

#include "Card.h"

class Player {

private:
	std::string name;

public:
	CardPack cards;

public:
	Player(std::string name);

	std::string getName() const;

	Card &topCard();
};


#endif //ICP2015CLIENT_PLAYER_H
