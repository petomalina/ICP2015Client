/**
 * @brief ICP project 2015 (Maze game)
 * @authors xmalin26, xmasek15
 */

#ifndef ICP2015CLIENT_LABYRINTHITEM_H
#define ICP2015CLIENT_LABYRINTHITEM_H

#include <QtWidgets/QGraphicsPixmapItem>
#include "../Fragment.h"
#include "../../ContentManager.h"

class GUIBlock: public QObject, public QGraphicsPixmapItem {
Q_OBJECT

public:
	// Size in pixels for each Block
	static const int Size = 40;

public:
	std::shared_ptr<Fragment> Frag; // linked fragment

public:
	GUIBlock(std::shared_ptr<Fragment> frag);

	GUIBlock(std::shared_ptr<Fragment> frag, QPixmap pixmap);

	virtual ~GUIBlock();

private:
	/**
	 * Initializes the block (internal use)
	 */
	void initialize();

public:
	/**
	 * Sets the position for the block
	 * @param x position
	 * @param y position
	 */
	void setPosition(int x, int y);

	/**
	 * Moves the block in the given direction
	 * @param dx direction
	 * @param dy direction
	 */
	void move(int dx, int dy);

	/**
	 * Rotates the block to the given rotation
	 * @param rot FragmentRotation
	 */
	void rotate(FragmentRotation rot);
};


#endif //ICP2015CLIENT_LABYRINTHITEM_H
