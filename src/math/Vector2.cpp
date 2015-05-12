/**
 * @brief ICP project 2015 (Maze game)
 * @authors xmalin26, xmasek15
 */

#include "Vector2.h"

Vector2::Vector2(int x, int y)
{
	this->set(x, y);
}

Vector2::~Vector2()
{

}

int Vector2::x() const
{
	return this->xpos;
}

int Vector2::y() const
{
	return this->ypos;
}

int &Vector2::rx()
{
	return this->xpos;
}

int &Vector2::ry()
{
	return this->ypos;
}

void Vector2::setX(int x)
{
	this->xpos = x;
}

void Vector2::setY(int y)
{
	this->ypos = y;
}

void Vector2::set(int x, int y)
{
	this->xpos = x;
	this->ypos = y;
}

void Vector2::move(int dx, int dy)
{
	this->xpos += dx;
	this->ypos += dy;
}

void Vector2::move(const Vector2 &vec)
{
	this->xpos += vec.x();
	this->ypos += vec.x();
}
