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
	int size;

	std::vector<LabyrinthItem*> fragments;

public:
	CLIView(int size);

	void initialize();

	void show();

	void generateMap();
};


#endif //ICP2015CLIENT_CLIVIEW_H
