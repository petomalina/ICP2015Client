/**
 * @brief ICP project 2015 (Maze game)
 * @authors xmalin26, xmasek15
 */

#include "CLIBlock.h"

CLIBlock::CLIBlock(Fragment *frag)
{
	this->Frag = frag;
	this->initialize();
}

void CLIBlock::initialize()
{
	switch (this->Frag->Type) {
		case FragmentType::L:
			//this->Pixels = {'#', '#', '#', '#', 'L', ' ', '#', ' ', '#'};
			this->Pixels = {'#', '#', '#', '#', ' ', ' ', '#', ' ', '#'};
			break;

		case FragmentType::T:
			//this->Pixels = {'#', '#', '#', ' ', 'T', ' ', '#', ' ', '#'};
			this->Pixels = {'#', '#', '#', ' ', ' ', ' ', '#', ' ', '#'};
			break;

		case FragmentType::I:
			//this->Pixels = {'#', ' ', '#', '#', 'I', '#', '#', ' ', '#'};
			this->Pixels = {'#', ' ', '#', '#', ' ', '#', '#', ' ', '#'};
			break;
	}


	switch (this->Frag->getRotation()) {
		case FragmentRotation::Right:
			this->rotateRight();
			break;

		case FragmentRotation::Left:
			this->rotateLeft();
			break;

		case FragmentRotation::Flip:
			this->rotateFlip();
			break;

		default:
			break;
	}
}


CLIBlock *CLIBlock::rotate(FragmentRotation rotation)
{
	// TODO: logic for each turn
	if (this->Frag->getRotation() == FragmentRotation::Normal) {

	} else if (this->Frag->getRotation() == FragmentRotation::Left) {

	} else if (this->Frag->getRotation() == FragmentRotation::Right) {

	} else { // flipped

	}

	this->Frag->rotate(rotation);
	return this;
}

CLIBlock *CLIBlock::rotateLeft()
{
	std::array<char, 9> rotated = this->Pixels;

	rotated[0] = this->Pixels[2];
	rotated[1] = this->Pixels[5];
	rotated[2] = this->Pixels[8];
	rotated[3] = this->Pixels[1];
	rotated[5] = this->Pixels[7];
	rotated[6] = this->Pixels[0];
	rotated[7] = this->Pixels[3];
	rotated[8] = this->Pixels[6];

	this->Pixels = rotated;
	return this;
}

CLIBlock *CLIBlock::rotateRight()
{
	std::array<char, 9> rotated = this->Pixels;

	rotated[0] = this->Pixels[6];
	rotated[1] = this->Pixels[3];
	rotated[2] = this->Pixels[0];
	rotated[3] = this->Pixels[7];
	rotated[5] = this->Pixels[1];
	rotated[6] = this->Pixels[8];
	rotated[7] = this->Pixels[5];
	rotated[8] = this->Pixels[2];

	this->Pixels = rotated;
	return this;
}

CLIBlock *CLIBlock::rotateFlip()
{
	std::array<char, 9> rotated = this->Pixels;

	rotated[0] = this->Pixels[8];
	rotated[1] = this->Pixels[7];
	rotated[2] = this->Pixels[6];
	rotated[3] = this->Pixels[5];
	rotated[5] = this->Pixels[3];
	rotated[6] = this->Pixels[2];
	rotated[7] = this->Pixels[1];
	rotated[8] = this->Pixels[0];

	this->Pixels = rotated;
	return this;
}

std::string CLIBlock::getFirstRow()
{
	return std::string() + this->Pixels[0] + " " + this->Pixels[1] + " " + this->Pixels[2] + " ";
}

std::string CLIBlock::getSecondRow()
{
	return std::string() + this->Pixels[3] + " " + this->Pixels[4] + " " + this->Pixels[5] + " ";
}

std::string CLIBlock::getThirdRow()
{
	return std::string() + this->Pixels[6] + " " + this->Pixels[7] + " " + this->Pixels[8] + " ";
}
