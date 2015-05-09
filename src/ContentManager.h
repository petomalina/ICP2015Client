//
// Created by gelidus on 5.5.2015.
//

#ifndef ICP2015CLIENT_CONTENTMANAGER_H
#define ICP2015CLIENT_CONTENTMANAGER_H

#include <map>
#include <string>
#include <QtWidgets/QGraphicsPixmapItem>

class ContentManager {

protected:
	// Textures alias for map
	using Textures = std::map<std::string, QPixmap>;

	Textures textures;
public:
	void addTexture(std::string name, std::string path);

	void addTexture(std::string name, QPixmap pixmap);

	QPixmap getTexture(std::string name);

public: // Singleton
	static ContentManager &get()
	{
		static ContentManager instance;
		return instance;
	}
};

#define SContentManager ContentManager::get()


#endif //ICP2015CLIENT_CONTENTMANAGER_H
