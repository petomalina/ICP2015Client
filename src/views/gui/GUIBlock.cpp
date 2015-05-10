//
// Created by gelidus on 5.5.2015.
//

#include "GUIBlock.h"

GUIBlock::GUIBlock(Fragment *frag):
		QGraphicsPixmapItem(
				SContentManager.getTexture(frag->Type == FragmentType::L ? "L" : frag->Type == FragmentType::I ? "I" : "T"))
{
	this->Frag = frag;
	this->setPosition(frag->getX(), frag->getY());
}

GUIBlock::~GUIBlock()
{

}

void GUIBlock::setPosition(int x, int y)
{
	this->setPos(x * GUIBlock::Size, y * GUIBlock::Size);
	this->Frag->setPosition(x, y);
}

void GUIBlock::move(int dx, int dy)
{
	this->moveBy(dx * GUIBlock::Size, dy * GUIBlock::Size);
	this->Frag->move(dx, dy);
}
