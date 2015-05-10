//
// Created by gelidus on 10.5.2015.
//

#ifndef ICP2015CLIENT_FRAGMENT_H
#define ICP2015CLIENT_FRAGMENT_H

#include <algorithm>

enum class FragmentType: int {
	L = 0, T = 1, I = 2
};

enum class FragmentRotation: int {
	Normal = 0, Left = 1, Right = 2, Flip = 3
};

class Fragment {

public:
	const FragmentType Type;

private:
	int x, y;
	FragmentRotation rotation;

public:
	Fragment(int x, int y, FragmentType type, FragmentRotation rotation);
	~Fragment();

	FragmentRotation getRotation() const;
	int getX() const;
	int getY() const;

	virtual void setPosition(int x, int y);
	virtual void move(int dx, int dy);

	virtual void rotate(FragmentRotation rotation);
};

class FragmentFactory {

public:
	static Fragment *create(int x, int y, FragmentType type, FragmentRotation rot = FragmentRotation::Normal) {
		return new Fragment(x, y, type, rot);
	}

	static Fragment *createRandom(int x, int y) {

		FragmentType type = static_cast<FragmentType>(rand() % 3);
		FragmentRotation rot = static_cast<FragmentRotation>(rand() % 4);

		return new Fragment(x, y, type, rot);
	}
};


#endif //ICP2015CLIENT_FRAGMENT_H
