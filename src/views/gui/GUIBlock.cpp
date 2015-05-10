//
// Created by gelidus on 5.5.2015.
//

#include "GUIBlock.h"

GUIBlock::GUIBlock(Fragment *frag):
		QGraphicsPixmapItem(
				SContentManager.getTexture(frag->Type == FragmentType::L ? "L" : frag->Type == FragmentType::I ? "I" : "T"))
{
	this->Frag = frag;
	this->initialize();
}

GUIBlock::GUIBlock(Fragment *frag, QPixmap pixmap) : QGraphicsPixmapItem(pixmap)
{
	this->Frag = frag;
	this->initialize();
}

GUIBlock::~GUIBlock()
{

}


void GUIBlock::initialize()
{
	this->setPosition(this->Frag->getX(), this->Frag->getY());
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

void GUIBlock::rotate(FragmentRotation rot)
{

}
