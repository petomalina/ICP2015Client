//
// Created by gelidus on 6.5.2015.
//

#include "LabyrinthItem.h"
#include <algorithm>

LabyrinthItem *LabyrinthItem::rotateLeft()
{
	LabyrinthItem *rotated = new LabyrinthItem(this->Pixels);
	// TODO: rotate

	return rotated;
}

LabyrinthItem *LabyrinthItem::rotateRight()
{
	LabyrinthItem *rotated = new LabyrinthItem(this->Pixels);

	for (int i = 0; i < 3; ++i)
		for (int j = i + 1; j < 3; ++j)
			std::swap(rotated[i+j], rotated[j+i]);

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3 / 2; ++j)
			std::swap(rotated[i+j], rotated[i+3 - j - 1]);

	return rotated;
}

LabyrinthItem *LabyrinthItem::rotateFlip()
{
	LabyrinthItem *rotated = new LabyrinthItem(this->Pixels);

	for (int i = 0; i < 4; ++i) {
		auto temp = rotated[9 - i - 1];
		rotated[9 - i - 1] = rotated[i];
		rotated[i] = temp;
	}

	return rotated;
}

LabyrinthItem *LabyrinthItem::transpose()
{
	LabyrinthItem *transposed = new LabyrinthItem(this->Pixels);

	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 3; j++) {
			auto tmp = transposed[i + j];
			transposed[i + j] = transposed[j + i];
			transposed[j + i] = tmp;
		}
	}
	return transposed;
}

LabyrinthItem *LabyrinthItem::swapColumns()
{
	LabyrinthItem *swapped = new LabyrinthItem(this->Pixels);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3 / 2; j++) {
			auto tmp = swapped[i + j];
			swapped[i + j] = swapped[i + 3 - 1 - j];
			swapped[i + 3 - 1 - j] = tmp;
		}
	}

	return swapped;
}

LabyrinthItem *LabyrinthItem::swapRows()
{
	LabyrinthItem *swapped = new LabyrinthItem(this->Pixels);

	for (int i = 0; i < 3; ++i) {
		auto temp = swapped[0 + 3];
		swapped[0 + i] = swapped[1 + i];
		swapped[1 + i] = temp;
	}

	return swapped;
}
