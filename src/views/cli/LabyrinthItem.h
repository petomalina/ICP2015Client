//
// Created by gelidus on 6.5.2015.
//

#ifndef ICP2015CLIENT_LABYRINTHITEM_H
#define ICP2015CLIENT_LABYRINTHITEM_H


#include <array>
#include <memory>

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
	LabyrinthItem *swapColumns();
	LabyrinthItem *swapRows();
};

class LabyrinthItemFactory {

public:
	LabyrinthItem *L();
	LabyrinthItem *T();
	LabyrinthItem *I();
};


#endif //ICP2015CLIENT_LABYRINTHITEM_H
