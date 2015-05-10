//
// Created by gelidus on 5.5.2015.
//

#include "GUIBlock.h"

GUIBlock::GUIBlock(Fragment *frag):
		QGraphicsPixmapItem(
				SContentManager.getTexture(frag->Type == FragmentType::L ? "L" : frag->Type == FragmentType::I ? "I" : "T"))
{
	this->setFlag(GraphicsItemFlag::ItemIsFocusable);
}

GUIBlock::~GUIBlock()
{

}

void GUIBlock::setPosition(int x, int y)
{
	this->setPos(x * Width, y * Height);
	this->Frag->setPosition(x, y);
}

void GUIBlock::move(int dx, int dy)
{
	this->moveBy(dx * Width, dy * Height);
	this->Frag->move(dx, dy);
}
