//
// Created by gelidus on 5.5.2015.
//

#ifndef ICP2015CLIENT_LABYRINTHITEM_H
#define ICP2015CLIENT_LABYRINTHITEM_H

#include <QtWidgets/QGraphicsPixmapItem>
#include "../Fragment.h"
#include "../../ContentManager.h"

class LabyrinthItem: public QObject, public QGraphicsPixmapItem, public Fragment {
Q_OBJECT

public:
	static const int Width = 40;
	static const int Height = 40;

public:
	LabyrinthItem(FragmentType type, FragmentRotation rotation, int x = 0, int y = 0);
	~LabyrinthItem();

public:
	virtual void setPosition(int x, int y) override;

	virtual void move(int x, int y) override;
};


#endif //ICP2015CLIENT_LABYRINTHITEM_H
