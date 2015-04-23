#include "src/Client.h"

#include <QtCore/QtCore>

int main (int argc, char *argv[])
{
	QCoreApplication application{argc, argv};
	Client client{};

	return static_cast<int>(client.run());
}