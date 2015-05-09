//
// Created by gelidus on 10.5.2015.
//

#ifndef ICP2015CLIENT_FRAGMENT_H
#define ICP2015CLIENT_FRAGMENT_H

enum class FragmentType {
	L, T, I
};

enum class FragmentRotation {
	Normal, Left, Right, Flip
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

	static Fragment *create(FragmentType type, FragmentRotation rot = FragmentRotation::Normal) {
		return new Fragment(0, 0, type, rot);
	}
};


#endif //ICP2015CLIENT_FRAGMENT_H
