#include "src/Client.h"

#include <QtGui/QGuiApplication>
//#include <QtGui/QSurface>

int main (int argc, char *argv[])
{
	QGuiApplication application{argc, argv};

	Client client{};

	return application.exec();
}