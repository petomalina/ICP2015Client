cmake_minimum_required(VERSION 3.1)
project(ICP2015Client)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES

    main.cpp

    src/Client.h
    src/Client.cpp

    src/controllers/LabyrinthController.h
    src/controllers/LabyrinthController.cpp
    src/controllers/PlayerController.h
    src/controllers/PlayerController.cpp
)

add_executable(ICP2015Client ${SOURCE_FILES} src/Client.cpp src/Client.h)