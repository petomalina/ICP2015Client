//
// Created by gelidus on 5.5.2015.
//

#ifndef ICP2015CLIENT_CARD_H
#define ICP2015CLIENT_CARD_H

enum class CardType: int {
	APPLE = 1,
	PEAR = 2,
	// TODO
};

class Card {

private:
	CardType type;

public:
	Card(CardType type);

	CardType getType();
};


#endif //ICP2015CLIENT_CARD_H
