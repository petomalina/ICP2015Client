//
// Created by gelidus on 5.5.2015.
//

#ifndef ICP2015CLIENT_LABYRINTHITEM_H
#define ICP2015CLIENT_LABYRINTHITEM_H

#include <QtWidgets/QGraphicsPixmapItem>
#include "../Fragment.h"
#include "../../ContentManager.h"

class LabyrinthItem: public QObject, public QGraphicsPixmapItem {
Q_OBJECT

public:
	static const int Width = 40;
	static const int Height = 40;

public:
	Fragment *Frag; // linked fragment

public:
	LabyrinthItem(FragmentType type, FragmentRotation rotation, int x = 0, int y = 0);
	~LabyrinthItem();

public:
	void setPosition(int x, int y);

	void move(int x, int y);
};


#endif //ICP2015CLIENT_LABYRINTHITEM_H
