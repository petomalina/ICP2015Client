//
// Created by gelidus on 6.5.2015.
//

#ifndef ICP2015CLIENT_LABYRINTHITEM_H
#define ICP2015CLIENT_LABYRINTHITEM_H


#include <array>

// Base class, no constructor
class LabyrinthItem {

private:
	std::array<char, 9> pixels;

protected:
	LabyrinthItem(std::array<char, 9> pixels) {
		this->pixels = pixels;
	}

public:
	std::array<char, 9> getPixels();

	LabyrinthItem rotateLeft();
	LabyrinthItem rotateRight();
	LabyrinthItem rotateFlip();
};

// Class for L item
class LabyrinthItemL: public LabyrinthItem {

public:
	LabyrinthItemL();
};


#endif //ICP2015CLIENT_LABYRINTHITEM_H
