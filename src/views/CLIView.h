//
// Created by gelidus on 5.5.2015.
//

#ifndef ICP2015CLIENT_CLIVIEW_H
#define ICP2015CLIENT_CLIVIEW_H

#include <vector>

#include "cli/CLIBlock.h"
#include "IView.h"

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

	void prepareMap(std::vector<std::string> *map);

	char insertPlayer(int player, char field);

	void movePlayerFromIndex(char player, int x, int y);

	void clearScreen();

	void createMovingBlocks();

	char calculatePlayer(int player);

	int decodePlayer(char pixel);
};


#endif //ICP2015CLIENT_CLIVIEW_H
