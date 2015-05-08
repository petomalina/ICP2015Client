#include <QtWidgets/QApplication>

#include "Game.h"

int main (int argc, char *argv[])
{
	QApplication application{argc, argv};

	int playgroundSize = 7;

	GUIView view{playgroundSize};
	//CLIView view{playgroundSize};

	Game game{&view};
	game.run();

	return application.exec();
}