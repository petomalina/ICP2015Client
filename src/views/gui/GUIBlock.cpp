/**
 * @brief ICP project 2015 (Maze game)
 * @authors xmalin26, xmasek15
 */

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
	QGraphicsPixmapItem::setTransformOriginPoint(QGraphicsPixmapItem::boundingRect().center());

	// save rotation and rotate
	FragmentRotation rot = this->Frag->getRotation();
	this->Frag->rotate(FragmentRotation::Normal);
	this->rotate(rot);
}

void GUIBlock::setPosition(int x, int y)
{
	this->setPos(x * GUIBlock::Size, (y + 1) * GUIBlock::Size);
	this->Frag->set(x, y);
}

void GUIBlock::move(int dx, int dy)
{
	this->moveBy(dy * GUIBlock::Size, dx * GUIBlock::Size);
	this->Frag->move(dx, dy);
}

void GUIBlock::rotate(FragmentRotation rot)
{
	switch(rot) {
		case FragmentRotation::Normal:
			QGraphicsPixmapItem::setRotation(0);
			break;
		case FragmentRotation::Right:
			QGraphicsPixmapItem::setRotation(90);
			break;
		case FragmentRotation::Left:
			QGraphicsPixmapItem::setRotation(-90);
			break;
		case FragmentRotation::Flip:
			QGraphicsPixmapItem::setRotation(180);
			break;
	}

	this->Frag->rotate(rot);
}
