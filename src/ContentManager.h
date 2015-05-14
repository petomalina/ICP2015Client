/**
 * @brief ICP project 2015 (Maze game)
 * @authors xmalin26, xmasek15
 */

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
	/**
	 * Adds texture into collection
	 * @param name name of the textures
	 * @param path path to texture
	 */
	void addTexture(std::string name, std::string path);

	void addTexture(std::string name, QPixmap pixmap);

	/**
	 * Returns given textures
	 * @param  name texture name
	 * @return      Texture
	 */
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
