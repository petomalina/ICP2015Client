/**
 * @brief ICP project 2015 (Maze game)
 * @authors xmalin26, xmasek15
 */

#ifndef ICP2015CLIENT_CARDPACKGENERATOR_H
#define ICP2015CLIENT_CARDPACKGENERATOR_H

#include "Card.h"

/**
 * CardPackGenerator is generator for card packs for players
 */
class CardPackGenerator {

private:
	int size;

public:
	CardPackGenerator(int size);

	/**
	 * Generates new pack of shuffled cards
	 * @param pack of cards to be populated
	 */
	void generatePack(CardPack &pack);
};


#endif //ICP2015CLIENT_CARDPACKGENERATOR_H
