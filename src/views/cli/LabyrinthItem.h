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
	LabyrinthItem(std::array<char, 9> pixels)
	{
		this->Pixels = pixels;
	}

	LabyrinthItem *rotateLeft();

	LabyrinthItem *rotateRight();

	LabyrinthItem *rotateFlip();

	std::string getFirstRow();
	std::string getSecondRow();
	std::string getThirdRow();


	std::string str();
};

class LabyrinthItemFactory {

public:
	LabyrinthItem *L();

	LabyrinthItem *T();

	LabyrinthItem *I();

	LabyrinthItem *getRandomLabyrinthItem();
};


#endif //ICP2015CLIENT_LABYRINTHITEM_H
