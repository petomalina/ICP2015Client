//
// Created by gelidus on 5.5.2015.
//

#include "LabyrinthItem.h"

LabyrinthItem::LabyrinthItem(FragmentType type, FragmentRotation rotation, int x, int y):
		QGraphicsPixmapItem(SContentManager.getTexture(type == FragmentType::L ? "L" : type == FragmentType::I ? "I" : "T")),
		Fragment(x, y, type, rotation)
{
	this->setFlag(GraphicsItemFlag::ItemIsFocusable);
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
