//
// Created by gelidus on 6.5.2015.
//

#ifndef ICP2015CLIENT_LABYRINTHITEM_H
#define ICP2015CLIENT_LABYRINTHITEM_H

#include <array>
#include <memory>
#include <iostream>
#include "../Fragment.h"

class LabyrinthItem {

public:
	Fragment *Frag;

	std::array<char, 9> Pixels;

public:
	LabyrinthItem(Fragment *frag);

private:
	void initialize();

	LabyrinthItem *rotateLeft();

	LabyrinthItem *rotateRight();

	LabyrinthItem *rotateFlip();

public:

	LabyrinthItem *rotate(FragmentRotation rotation);

	std::string getFirstRow();

	std::string getSecondRow();

	std::string getThirdRow();
};


#endif //ICP2015CLIENT_LABYRINTHITEM_H
