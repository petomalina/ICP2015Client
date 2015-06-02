/**
 * @brief ICP project 2015 (Maze game)
 * @authors xmalin26, xmasek15
 */


#ifndef ICP2015CLIENT_CLIVIEW_H
#define ICP2015CLIENT_CLIVIEW_H

#include <vector>

#include "cli/CLIBlock.h"
#include "IView.h"


#include <stdio.h>

#if __linux__

#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>

#endif

/**
 * @brief Enumeration for keys
 * @details used for keybindings in cli
 * 
 */
enum class KeyBindings: int {
	keySpace = 0x20,
	key0 = 0x30,
	key1 = 0x31,
	key2 = 0x32,
	key3 = 0x33,
	key4 = 0x34,
	key5 = 0x35,
	key6 = 0x36,
	key7 = 0x37,
	key8 = 0x38,
	key9 = 0x39,
	keyW = 0x77,
	keyA = 0x61,
	keyS = 0x73,
	keyD = 0x64,
	keyK = 0x6b,
	keyL = 0x6c,
	keyT = 0x74,
	keyX = 0x78,
	keyZ = 0x7a,
	keyR = 0x72
};

/**
 * @brief CLI view class
 * @details Provides command line simple gui
 * @return view
 */
class CLIView: public IView {

private:
	std::vector<CLIBlock *> blocks;

public:
	CLIView();

	virtual void initialize(GameData *game) override;

	virtual void show() override;

	/**
	 * @brief reflect data to view
	 * @details used to reload new data to current view, called when something has changed
	 */
	void reflect();

	/**
	 * @brief shows menu
	 */
	void showMenu();

	/**
	 * @brief shows game view
	 */
	void showGame();

	/**
	 * @brief shows game view
	 * @details draws a map and basic instructions for playing game
	 */
	void showGameMap();

	/**
	 * @brief shows game options
	 */
	void showOptions();

	/**
	 * @brief shows loading dialog
	 * @details will be used for preload a saved game
	 */
	void showLoadDialog();

	/**
	 * @brief shows menu to set name of the game
	 */
	void showSetGameName();

	/**
	 * @brief shows menu to set players count
	 */
	void showSetPlayers();

	/**
	 * @brief shows menu to set size of the maze
	 */
	void showSetSize();

	/**
	 * @brief prepares map for drawing by cli view
	 * @details prepares map for drawing, inserts players and calls methodes to handle players and moving block
	 * 
	 * @param map vector of generated map fragments
	 */
	void prepareMap(std::vector<std::string> *map);

	/**
	 * @brief the firs and last row creating
	 * @details the first/last row map is containing only empty fragments and possibly moving block
	 * 
	 * @param rows vector map rows
	 * @param moving fragment of map symbolizing moving block
	 * @param empty empty block used for inserting empty (nonmoving blocks)
	 * @param index symbolizing first/last row of map
	 */
	void prepareFirstLastRow(std::vector<std::string> *rows, CLIBlock *moving, CLIBlock *empty, int index);

	/**
	 * @brief firs and last column creating
	 * @details the first/last row map is containing only empty fragments and possibly moving block
	 * 
	 * @param first row of map containing the first three chars of map pixels
	 * @param second row of map containing the second three chars of map pixels
	 * @param third row of map containing the third three chars of map pixels
	 * @param moving fragment of map symbolizing moving block
	 * @param empty empty block used for inserting empty (nonmoving blocks)
	 * @param index symbolizing first/last column of map
	 * @param row index of current row of map
	 */
	void prepareFirstLastCol(std::string *first, std::string *second, std::string *third, CLIBlock *moving,
							 CLIBlock *empty, int index, int row);

	/**
	 * @brief inserting players to blocks
	 * 
	 * @param player identifier
	 * @param field current field (other players may be placed here already)
	 *  
	 * @return symbol '[0-9A-F]' (sum of players)
	 */
	char insertPlayer(int player, const char field);

	/**
	 * @brief method is inserting representation of treasures as lowercase characters
	 *
	 * @param type treasure to be inserted
	 *
	 * @return lowercase character representation of treasure
	 */
	char insertTreasure(CardType type, const char field);

	/**
	 * @brief clears screen
	 * @details just inserts 50 newlines
	 */
	void clearScreen();

	/**
	 * @brief calculates player for field
	 * 
	 * @param player identifier
	 * @return hex representation
	 */
	char calculatePlayer(int player);

	/**
	 * @brief decodes hex representation of players
	 * 
	 * @param pixel current field (players placed here)
	 * @return player/s identifier
	 */
	int decodePlayer(char pixel);

	/**
	 * @brief getchar function
	 * @details getchar funcion that (on linux machine) doesn't wait for enter
	 * @return pressed key (ascii char)
	 */
	int ourGetCh();
};


#endif //ICP2015CLIENT_CLIVIEW_H
