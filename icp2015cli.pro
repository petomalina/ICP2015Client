INCLUDEPATH += $$PWD/src/

CONFIG += c++11

MAKEFILE = Makefile_CLI

DEFINES += CLI_MODE

SOURCES += $$PWD/src/main.cpp
SOURCES += $$PWD/src/math/Vector2.cpp
SOURCES += $$PWD/src/Game.cpp
SOURCES += $$PWD/src/ContentManager.cpp
SOURCES += $$PWD/src/views/CLIView.cpp
SOURCES += $$PWD/src/views/Fragment.cpp
SOURCES += $$PWD/src/views/cli/CLIBlock.cpp
SOURCES += $$PWD/src/models/Card.cpp
SOURCES += $$PWD/src/models/CardPackGenerator.cpp
SOURCES += $$PWD/src/models/Player.cpp
SOURCES += $$PWD/src/models/Treasure.cpp

HEADERS += $$PWD/src/math/Vector2.h
HEADERS += $$PWD/src/Game.h
HEADERS += $$PWD/src/event/Event.h
HEADERS += $$PWD/src/event/EventListener.h
HEADERS += $$PWD/src/ContentManager.h
HEADERS += $$PWD/src/views/IView.h
HEADERS += $$PWD/src/views/CLIView.h
HEADERS += $$PWD/src/views/Fragment.h
HEADERS += $$PWD/src/views/cli/CLIBlock.h
HEADERS += $$PWD/src/models/Card.h
HEADERS += $$PWD/src/models/CardPackGenerator.h
HEADERS += $$PWD/src/models/Player.h
HEADERS += $$PWD/src/models/Treasure.h

target.path = ./qmaketarget
INSTALLS += target
