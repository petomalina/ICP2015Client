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
	static const int Size = 40;

public:
	Fragment *Frag; // linked fragment

public:
	GUIBlock(Fragment *frag);

	GUIBlock(Fragment *frag, QPixmap pixmap);

	virtual ~GUIBlock();

private:
	void initialize();

public:
	void setPosition(int x, int y);

	void move(int dx, int dy);

	void rotate(FragmentRotation rot);
};


#endif //ICP2015CLIENT_LABYRINTHITEM_H
