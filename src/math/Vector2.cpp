//
// Created by gelidus on 11.5.2015.
//

#include "Vector2.h"

Vector2::Vector2(int x, int y)
{
	this->set(x, y);
}

Vector2::~Vector2()
{

}

int Vector2::getX() const
{
	return this->x;
}

int Vector2::getY() const
{
	return this->y;
}

void Vector2::setX(int x)
{
	this->x = x;
}

void Vector2::setY(int y)
{
	this->y = y;
}

void Vector2::set(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Vector2::move(int dx, int dy)
{
	this->x += dx;
	this->y += dy;
}

void Vector2::move(const Vector2 &vec)
{
	this->x += vec.getX();
	this->y += vec.getY();
}
