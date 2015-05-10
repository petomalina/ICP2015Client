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
}

void GUIBlock::move(int x, int y)
{
	this->moveBy(x * Width, y * Height);
}
