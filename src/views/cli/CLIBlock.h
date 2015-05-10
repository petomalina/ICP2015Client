//
// Created by gelidus on 6.5.2015.
//

#ifndef ICP2015CLIENT_GUIBLOCK_H
#define ICP2015CLIENT_GUIBLOCK_H

#include <array>
#include <memory>
#include <iostream>
#include "../Fragment.h"

class CLIBlock {

public:
	Fragment *Frag;

	std::array<char, 9> Pixels;

public:
	CLIBlock(Fragment *frag);

private:
	void initialize();

	CLIBlock *rotateLeft();

	CLIBlock *rotateRight();

	CLIBlock *rotateFlip();

public:

	CLIBlock *rotate(FragmentRotation rotation);

	std::string getFirstRow();

	std::string getSecondRow();

	std::string getThirdRow();
};


#endif //ICP2015CLIENT_LABYRINTHITEM_H
