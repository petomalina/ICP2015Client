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

	void clearScreen();

	void createMovingBlocks();
};


#endif //ICP2015CLIENT_CLIVIEW_H
