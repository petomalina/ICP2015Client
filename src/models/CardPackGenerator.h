//
// Created by gelidus on 5.5.2015.
//

#ifndef ICP2015CLIENT_CARDPACKGENERATOR_H
#define ICP2015CLIENT_CARDPACKGENERATOR_H

#include <vector>
#include <string>

#include "Card.h"

using CardPack = std::vector<Card>;

class CardPackGenerator {

private:
	int size;

public:
	CardPackGenerator(int size);

	void generatePack(CardPack &pack);
};


#endif //ICP2015CLIENT_CARDPACKGENERATOR_H
