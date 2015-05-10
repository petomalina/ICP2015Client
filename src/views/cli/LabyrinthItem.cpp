//
// Created by gelidus on 6.5.2015.
//

#include "LabyrinthItem.h"

LabyrinthItem::LabyrinthItem(Fragment *frag)
{
	this->Frag = frag;
	this->initialize();
}

void LabyrinthItem::initialize()
{
	switch (this->Frag->Type) {
		case FragmentType::L:
			this->Pixels = {'#', '#', '#', ' ', ' ', ' ', '#', ' ', '#' };
			break;

		case FragmentType::T:
			this->Pixels = { '#', '#', '#', ' ', ' ', ' ', '#', ' ', '#' };
			break;

		case FragmentType::I:
			this->Pixels = {'#', ' ', '#', '#', ' ', '#', '#', ' ', '#' };
	}


	switch (this->Frag->getRotation()) {
		case FragmentRotation::Right:
			this->rotateRight(); break;

		case FragmentRotation::Left:
			this->rotateLeft(); break;

		case FragmentRotation::Flip:
			this->rotateFlip(); break;

		default:
			break;
	}
}

LabyrinthItem *LabyrinthItem::rotateLeft()
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

LabyrinthItem *LabyrinthItem::rotateRight()
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

LabyrinthItem *LabyrinthItem::rotateFlip()
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

/*LabyrinthItem *LabyrinthItemFactory::L()
{
	new LabyrinthItem{{
							  '#', '#', '#',
							  '#', ' ', ' ',
							  '#', ' ', '#',
					  }
	};
}

LabyrinthItem *LabyrinthItemFactory::T()
{
	return
			new LabyrinthItem{{
									  '#', '#', '#',
									  ' ', ' ', ' ',
									  '#', ' ', '#',
							  }
			};
}

LabyrinthItem *LabyrinthItemFactory::I()
{
	return
			new LabyrinthItem{{
									  '#', ' ', '#',
									  '#', ' ', '#',
									  '#', ' ', '#',
							  }
			};
}*/

std::string LabyrinthItem::getFirstRow()
{
	return std::string() + this->Pixels[0] + " " + this->Pixels[1] + " " + this->Pixels[2] + " ";
}

std::string LabyrinthItem::getSecondRow()
{
	return std::string() + this->Pixels[3] + " " + this->Pixels[4] + " " + this->Pixels[5] + " ";
}

std::string LabyrinthItem::getThirdRow()
{
	return std::string() + this->Pixels[6] + " " + this->Pixels[7] + " " + this->Pixels[8] + " ";
}
