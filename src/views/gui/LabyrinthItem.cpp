//
// Created by gelidus on 5.5.2015.
//

#include "LabyrinthItem.h"

LabyrinthItem::LabyrinthItem(QPixmap pixmap, int x, int y): QGraphicsPixmapItem(pixmap)
{
	this->setFlag(GraphicsItemFlag::ItemIsFocusable);
	this->setPosition(x, y);
}

LabyrinthItem::~LabyrinthItem()
{

}

void LabyrinthItem::setPosition(int x, int y)
{
	this->setPos(x*Width, y*Height);
}

void LabyrinthItem::move(int x, int y)
{
	this->moveBy(x*Width, y*Height);
}
