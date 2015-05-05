//
// Created by gelidus on 5.5.2015.
//

#include "LabyrinthItem.h"

LabyrinthItem::LabyrinthItem(QPixmap pixmap): QGraphicsPixmapItem(pixmap)
{
	this->setFlag(GraphicsItemFlag::ItemIsFocusable);
	this->setScale(2.5);
}

LabyrinthItem::~LabyrinthItem()
{

}
