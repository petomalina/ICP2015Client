INCLUDEPATH += $$PWD/src/


QT += core gui widgets

CONFIG += qt c++11

MAKEFILE = Makefile_GUI

SOURCES += $$PWD/src/main.cpp
SOURCES += $$PWD/src/math/Vector2.cpp
SOURCES += $$PWD/src/Game.cpp
SOURCES += $$PWD/src/ContentManager.cpp
SOURCES += $$PWD/src/views/GUIView.cpp
SOURCES += $$PWD/src/views/Fragment.cpp
SOURCES += $$PWD/src/views/gui/GUIBlock.cpp
SOURCES += $$PWD/src/models/Card.cpp
SOURCES += $$PWD/src/models/CardPackGenerator.cpp
SOURCES += $$PWD/src/models/Player.cpp

HEADERS += $$PWD/src/math/Vector2.h
HEADERS += $$PWD/src/Game.h
HEADERS += $$PWD/src/event/Event.h
HEADERS += $$PWD/src/event/EventListener.h
HEADERS += $$PWD/src/ContentManager.h
HEADERS += $$PWD/src/views/IView.h
HEADERS += $$PWD/src/views/GUIView.h
HEADERS += $$PWD/src/views/Fragment.h
HEADERS += $$PWD/src/views/gui/GUIBlock.h
HEADERS += $$PWD/src/models/Card.h
HEADERS += $$PWD/src/models/CardPackGenerator.h
HEADERS += $$PWD/src/models/Player.h


target.path = ./qmaketarget
INSTALLS += target
