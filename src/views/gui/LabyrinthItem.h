//
// Created by gelidus on 5.5.2015.
//

#ifndef ICP2015CLIENT_LABYRINTHITEM_H
#define ICP2015CLIENT_LABYRINTHITEM_H

#include <QtWidgets/QGraphicsPixmapItem>

class LabyrinthItem: public QObject, public QGraphicsPixmapItem {
Q_OBJECT

public:
	static const int Width = 40;
	static const int Height = 40;

private:
	

public:
	LabyrinthItem(QPixmap pixmap);
	~LabyrinthItem();
};


#endif //ICP2015CLIENT_LABYRINTHITEM_H
