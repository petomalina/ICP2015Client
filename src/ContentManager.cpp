//
// Created by gelidus on 5.5.2015.
//

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
