#include <QtWidgets/QApplication>

#include "Game.h"

int main(int argc, char *argv[])
{
	QApplication application{argc, argv}; //FIXME: will it be correct to use Qapp when cli is on ?

	int playgroundSize = 7;
	srand((unsigned)time(NULL)); //seed for pseudo random number generating

	//Preprocessor define macro must be set to run game in CLI mode, use -DCLI_MODE flag when compiling program
#ifndef CLI_MODE
	GUIView view{};
#else
	CLIView view{};
#endif

	Game game{&view};
	game.run();

	return application.exec();
}