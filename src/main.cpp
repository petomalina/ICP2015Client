#include <QtWidgets/QApplication>

#include "Client.h"

int main (int argc, char *argv[])
{
	QApplication application{argc, argv};

	int playgroundSize = 7;

	GUIView view{playgroundSize};
	//CLIView view{playgroundSize};

	view.initialize();
	view.show();

	return application.exec();
}