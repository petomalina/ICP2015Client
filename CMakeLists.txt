cmake_minimum_required(VERSION 3.1)
project(ICP2015Client)

SET (CMAKE_CXX_FLAGS "-fPIC") # qt thingy

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES

    src/main.cpp

    src/Client.h
    src/Client.cpp

    src/ContentManager.h
    src/ContentManager.cpp

    src/controllers/LabyrinthController.h
    src/controllers/LabyrinthController.cpp
    src/controllers/PlayerController.h
    src/controllers/PlayerController.cpp

    src/views/GUIView.h
    src/views/GUIView.cpp
    src/views/CLIView.h
    src/views/CLIView.cpp

    src/views/gui/LabyrinthItem.h
    src/views/gui/LabyrinthItem.cpp
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

add_custom_command(TARGET ICP2015Client PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/graphics $<TARGET_FILE_DIR:ICP2015Client>/graphics)