//
// Created by gelidus on 5.5.2015.
//

#include "ContentManager.h"

void ContentManager::AddTexture(std::string name, std::string path)
{
	this->textures[name] = QPixmap{path.c_str()};
}

void ContentManager::AddTexture(std::string name, QPixmap pixmap)
{
	this->textures[name] = pixmap;
}

QPixmap ContentManager::GetTexture(std::string name)
{
	return this->textures[name];
}
