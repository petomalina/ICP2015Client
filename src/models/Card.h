/**
 * @brief ICP project 2015 (Maze game)
 * @authors xmalin26, xmasek15
 */


#ifndef ICP2015CLIENT_CARD_H
#define ICP2015CLIENT_CARD_H

#include <vector>


enum class CardType: unsigned int {
	APPLE = 1,
	PEAR = 2,
	BANANA = 3,
	MELON = 4,
	LEMON = 5,
	PEACH = 6,
	POTATO = 7,
	PINEAPPLE = 8,
	SHERRY = 9,
	TOMATO = 10,
	ORANGE = 11,
	MANDARIN = 12
	// TODO: Change names and get icons for object over elements
};

class Card {

private:
	CardType type;

public:
	Card(CardType type);

	CardType getType();
};

using CardPack = std::vector<Card>;

#endif //ICP2015CLIENT_CARD_H
