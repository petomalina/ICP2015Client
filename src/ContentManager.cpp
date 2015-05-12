/**
 * @brief ICP project 2015 (Maze game)
 * @authors xmalin26, xmasek15
 */

#include "ContentManager.h"

void ContentManager::addTexture(std::string name, std::string path)
{
	this->textures[name] = QPixmap{path.c_str()};
}

void ContentManager::addTexture(std::string name, QPixmap pixmap)
{
	this->textures[name] = pixmap;
}

QPixmap ContentManager::getTexture(std::string name)
{
	return this->textures[name];
}
