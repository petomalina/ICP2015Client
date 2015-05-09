//
// Created by gelidus on 10.5.2015.
//

#include "Fragment.h"

Fragment::Fragment(int x, int y, FragmentType type, FragmentRotation rotation): Type(type)
{
	this->setPosition(x, y);
	this->rotate(rotation);
}

Fragment::~Fragment()
{

}


FragmentRotation Fragment::getRotation() const
{
	return this->rotation;
}

int Fragment::getX() const
{
	return this->x;
}

int Fragment::getY() const
{
	return this->y;
}

void Fragment::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Fragment::move(int dx, int dy)
{
	this->x += dx;
	this->y += dy;
}

Fragment *Fragment::rotate(FragmentRotation rotation)
{
	this->rotation = rotation;
	return this;
}
