/**
 * @brief ICP project 2015 (Maze game)
 * @authors xmalin26, xmasek15
 */

#ifndef ICP2015CLIENT_FRAGMENT_H
#define ICP2015CLIENT_FRAGMENT_H

#include <algorithm>
#include <memory>
#include "../math/Vector2.h"

enum class FragmentType: int {
	L = 0, T = 1, I = 2, N = 3, Player = 4, Card = 5
};

enum class FragmentRotation: int {
	Normal = 0, Right = 1, Flip = 2, Left = 3
};

class Fragment: public Vector2 {

public:
	const FragmentType Type;

private:
	FragmentRotation rotation;

public:
	Fragment(int x, int y, FragmentType type, FragmentRotation rotation);

	virtual ~Fragment();

	FragmentRotation getRotation() const;

	/**
	 * Returns X value of position
	 * @return x pos
	 */
	int getX() const;

	/**
	 * Returns Y value of position
	 * @return y pos
	 */
	int getY() const;

	/**
	 * Returns true if is open on up side
	 * @return bool
	 */
	bool isOpenUp() const;

	/**
	 * Returns true if object is open down
	 * @return bool
	 */
	bool isOpenDown() const;

	/**
	 * Returns true if object is open to the righ
	 * @return bool
	 */
	bool isOpenRight() const;

	/**
	 * Retusn true if is open on the left side
	 * @return bool
	 */
	bool isOpenLeft() const;

	virtual void rotate(FragmentRotation rotation);
};

class FragmentFactory {

public:
	static std::shared_ptr<Fragment> create(int x, int y, FragmentType type, FragmentRotation rot = FragmentRotation::Normal)
	{
		return std::shared_ptr<Fragment>{new Fragment{x, y, type, rot}};
	};

	static std::shared_ptr<Fragment> createRandom(int x, int y)
	{

		FragmentType type = static_cast<FragmentType>(rand() % 3);
		FragmentRotation rot = static_cast<FragmentRotation>(rand() % 4);

		return std::shared_ptr<Fragment>{new Fragment{x, y, type, rot}};
	};
};


#endif //ICP2015CLIENT_FRAGMENT_H
