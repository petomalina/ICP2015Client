/**
 * @brief ICP project 2015 (Maze game)
 * @authors xmalin26, xmasek15
 */

#include "Fragment.h"

Fragment::Fragment(int x, int y, FragmentType type, FragmentRotation rotation): Type(type)
{
	Vector2::set(x, y);
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
	return this->x();
}

int Fragment::getY() const
{
	return this->y();
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
		return (this->rotation == FragmentRotation::Normal || this->rotation == FragmentRotation::Left);
	} else if (this->Type == FragmentType::T) {
		return (this->rotation != FragmentRotation::Right);
	} else if (this->Type == FragmentType::I) {
		return (this->rotation == FragmentRotation::Normal || this->rotation == FragmentRotation::Flip);
	}

	return false;
}

bool Fragment::isOpenLeft() const
{
	if (this->Type == FragmentType::L) {
		return (this->rotation == FragmentRotation::Right || this->rotation == FragmentRotation::Flip);
	} else if (this->Type == FragmentType::T) {
		return (this->rotation != FragmentRotation::Left);
	} else if (this->Type == FragmentType::I) {
		return (this->rotation == FragmentRotation::Normal || this->rotation == FragmentRotation::Flip);
	}

	return false;
}

void Fragment::rotate(FragmentRotation rotation)
{
	this->rotation = rotation;
}
