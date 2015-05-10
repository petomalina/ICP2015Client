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

bool Fragment::isOpenUp() const
{
	if (this->Type == FragmentType::L) {
		return (this->rotation == FragmentRotation::Flip || this->rotation == FragmentRotation::Left);
	} else if (this->Type == FragmentType::T) {
		return (this->rotation != FragmentRotation::Normal);
	} else if (this->Type == FragmentType::I) {
		return (this->rotation != FragmentRotation::Normal && this->rotation != FragmentRotation::Flip);
	}

	return false;
}

bool Fragment::isOpenDown() const
{
	if (this->Type == FragmentType::L) {
		return (this->rotation != FragmentRotation::Left && this->rotation != FragmentRotation::Flip);
	} else if (this->Type == FragmentType::T) {
		return (this->rotation != FragmentRotation::Flip);
	} else if (this->Type == FragmentType::I) {
		return (this->rotation != FragmentRotation::Normal && this->rotation != FragmentRotation::Flip);
	}

	return false;
}

bool Fragment::isOpenRight() const
{
	if (this->Type == FragmentType::L) {

	} else if (this->Type == FragmentType::T) {

	} else if (this->Type == FragmentType::I) {

	}

	return false;
}

bool Fragment::isOpenLeft() const
{
	if (this->Type == FragmentType::L) {

	} else if (this->Type == FragmentType::T) {

	} else if (this->Type == FragmentType::I) {

	}

	return false;
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

void Fragment::rotate(FragmentRotation rotation)
{
	this->rotation = rotation;
}
