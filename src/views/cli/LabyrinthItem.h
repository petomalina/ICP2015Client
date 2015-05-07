//
// Created by gelidus on 6.5.2015.
//

#ifndef ICP2015CLIENT_LABYRINTHITEM_H
#define ICP2015CLIENT_LABYRINTHITEM_H


#include <array>

// Base class, no constructor
class LabyrinthItem {

public:
	std::array<char, 9> Pixels;

public:
	LabyrinthItem(std::array<char, 9> pixels) {
		this->Pixels = pixels;
	}

	LabyrinthItem *rotateLeft();
	LabyrinthItem *rotateRight();
	LabyrinthItem *rotateFlip();
	LabyrinthItem *transpose();
	LabyrinthItem *swapColumns();
	LabyrinthItem *swapRows();
};

// Class for L item
class LabyrinthItemL: public LabyrinthItem {

public:
	LabyrinthItemL();
};


#endif //ICP2015CLIENT_LABYRINTHITEM_H
