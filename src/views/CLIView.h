//
// Created by gelidus on 5.5.2015.
//

#ifndef ICP2015CLIENT_CLIVIEW_H
#define ICP2015CLIENT_CLIVIEW_H

#include <vector>

#include "cli/LabyrinthItem.h"
#include "IView.h"

class CLIView: public IView {

private:
	std::vector<LabyrinthItem*> fragments;

public:
	CLIView();

	virtual void initialize(GameData *game) override;

	virtual void show() override;

	void showMenu();

	void showGame();

	std::vector<std::string> prepareMap();

	void clearScreen();

	void createMovingBlocks();
};


#endif //ICP2015CLIENT_CLIVIEW_H
