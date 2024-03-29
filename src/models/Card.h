/**
 * @brief ICP project 2015 (Maze game)
 * @authors xmalin26, xmasek15
 */


#ifndef ICP2015CLIENT_CARD_H
#define ICP2015CLIENT_CARD_H

#include <vector>


enum class CardType: unsigned int {
	A = 1,
	B = 2,
	C = 3,
	D,
	E,
	F,
	G,
	H,
	I,
	J,

	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,

	U,
	V,
	X,
	Y,
	Z
};

class Card {

private:
	CardType type;

public:
	Card(CardType type);

	/**
	 * Returns given card type
	 * @return type of card
	 */
	CardType getType();
};

using CardPack = std::vector<Card>;

#endif //ICP2015CLIENT_CARD_H
