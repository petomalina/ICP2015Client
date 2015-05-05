#include "Client.h"
#include "views/GUIView.h"

#include <QtWidgets/QApplication>

#include <QtWidgets/QGraphicsRectItem>

int main (int argc, char *argv[])
{
	QApplication application{argc, argv};

	QGraphicsScene *scene = new QGraphicsScene{};

	QGraphicsRectItem *rect = new QGraphicsRectItem{};
	rect->setRect(0, 0, 100, 100);

	scene->addItem(rect);

	GUIView view{scene};
	view.show();

	return application.exec();
}