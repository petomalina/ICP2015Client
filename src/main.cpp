#include "Client.h"
#include "views/GUIView.h"

#include <QtWidgets/QApplication>

int main (int argc, char *argv[])
{
	QApplication application{argc, argv};

	int playgroundSize = 7;

	GUIView view{};
	view.show();

	return application.exec();
}