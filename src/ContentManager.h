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
	void AddTexture(std::string name, std::string path);

	void AddTexture(std::string name, QPixmap pixmap);

	QPixmap GetTexture(std::string name);

	// singleton part
private:
	static ContentManager *instance;

public: // Singleton method
	static ContentManager *get()
	{
		if (instance == nullptr) {
			instance = new ContentManager{};
		}

		return instance;
	}
};

#define SContentManager ContentManager.get()


#endif //ICP2015CLIENT_CONTENTMANAGER_H
