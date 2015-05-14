/**
 * @brief ICP project 2015 (Maze game)
 * @authors xmalin26, xmasek15
 */

#ifndef ICP2015CLIENT_GUIBLOCK_H
#define ICP2015CLIENT_GUIBLOCK_H

#include <array>
#include <memory>
#include <iostream>
#include <exception>

#include "../Fragment.h"

class CLIException : public std::exception
{
private:
	const std::string message;

public:
	CLIException(std::string msg) : message(msg) { }

	const char * what () const throw () override
	{
		return this->message.c_str();
	}
};

class CLIBlock {

public:
	// Fragment for block
	Fragment *Frag;

	// array of chars that represents block in console view
	std::array<char, 9> Pixels;

public:
	CLIBlock(Fragment *frag);

private:
	void initialize();

	CLIBlock *rotateRight();

public:

	CLIBlock *rotate(FragmentRotation rotation);

	/**
	 * Returns first row of the pixel area in string
	 * @return pixel area
	 */
	std::string getFirstRow();

	/**
	 * Returns second row of the pixel area in string
	 * @return pixel area
	 */
	std::string getSecondRow();

	/**
	 * Returns third row of the pixel area in string
	 * @return pixel area
	 */
	std::string getThirdRow();
};


#endif //ICP2015CLIENT_LABYRINTHITEM_H
