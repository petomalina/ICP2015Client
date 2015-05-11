//
// Created by gelidus on 5.5.2015.
//

#ifndef ICP2015CLIENT_CLIVIEW_H
#define ICP2015CLIENT_CLIVIEW_H

#include <vector>

#include "cli/CLIBlock.h"
#include "IView.h"


#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>

enum class KeyBindings: int {
	keyEscape = 0x01000000,
	keyBackspace = 0x01000003,
	keyEnter = 0x01000005,
	keyF1 = 0x01000030,
	keySpace = 0x20,
	keyLeft = 0x01000012,
	keyUp = 0x01000013,
	keyRight = 0x01000014,
	keyDown = 0x01000015,
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
	keyC = 0x43,
	keyD = 0x44,
	keyE = 0x45,
	keyV = 0x56,
};


class CLIView: public IView {

private:
	std::vector<CLIBlock *> blocks;

public:
	CLIView();

	virtual void initialize(GameData *game) override;

	virtual void show() override;

	void reflect();

	void showMenu();

	void showGame();

	void showOptions();

	void showLoadDialog();

	void showSetGameName();

	void showSetPlayers();

	void showSetSize();

	void prepareMap(std::vector<std::string> *map);

	char insertPlayer(int player, char field);

	void movePlayerFromIndex(char player, int x, int y);

	void clearScreen();

	void createMovingBlocks();

	char calculatePlayer(int player);

	int decodePlayer(char pixel);

	char ourGetCh();
};


#endif //ICP2015CLIENT_CLIVIEW_H
