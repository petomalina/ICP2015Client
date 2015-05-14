/**
 * @brief ICP project 2015 (Maze game)
 * @authors xmalin26, xmasek15
 */




#include "Game.h"


#ifdef CLI_MODE //Preprocessor define macro must be set to run game in CLI mode, use -DCLI_MODE flag when compiling program

int main()
{
	srand((unsigned) time(NULL)); //seed for pseudo random number generating

	CLIView view{};

	Game game{&view};
	game.run();

	return 0;
}

#else

#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{

	QApplication application{argc, argv};

	srand((unsigned) time(NULL)); //seed for pseudo random number generating

	GUIView view{};

	Game game{&view};
	game.run();

	return application.exec();
}

#endif
