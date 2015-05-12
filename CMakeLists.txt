cmake_minimum_required(VERSION 3.1)
project(ICP2015Client)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets)

set(CMAKE_CXX_FLAGS "-fPIC") # qt thingy
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(./lib)

include_directories(~/SOFTWARE/Qt/5.2.0/gcc_64/include/)
link_directories(~/SOFTWARE/Qt/5.2.0/gcc_64/plugins/platforms/)
link_directories(~/SOFTWARE/Qt/5.2.0/gcc_64/lib/)

set(SOURCE_FILES

    src/main.cpp

    src/math/Vector2.h
    src/math/Vector2.cpp

    src/Game.h
    src/Game.cpp

    src/event/Event.h
    src/event/EventListener.h

    src/ContentManager.h
    src/ContentManager.cpp

    src/views/IView.h
    src/views/GUIView.h
    src/views/GUIView.cpp
    src/views/CLIView.h
    src/views/CLIView.cpp

    src/views/Fragment.h
    src/views/Fragment.cpp
    src/views/gui/GUIBlock.h
    src/views/gui/GUIBlock.cpp
    src/views/cli/CLIBlock.h
    src/views/cli/CLIBlock.cpp

    src/models/Card.h
    src/models/Card.cpp
    src/models/CardPackGenerator.h
    src/models/CardPackGenerator.cpp
    src/models/Player.h
    src/models/Player.cpp
)

add_executable(ICP2015Client ${SOURCE_FILES})
target_link_libraries(ICP2015Client
    libqxcb.so
    libQt5Core.so
    libQt5Network.so
    libQt5OpenGL.so
    libQt5Gui.so
    libQt5Widgets.so
)

add_custom_command(TARGET ICP2015Client PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${CMAKE_SOURCE_DIR}/graphics $<TARGET_FILE_DIR:ICP2015Client>/graphics)

add_custom_command(TARGET ICP2015Client PRE_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory
                   $<TARGET_FILE_DIR:ICP2015Client>/games)