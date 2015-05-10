//
// Created by gelidus on 5.5.2015.
//

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

	virtual ~GUIBlock();

public:
	void setPosition(int x, int y);

	void move(int dx, int dy);
};


#endif //ICP2015CLIENT_LABYRINTHITEM_H
