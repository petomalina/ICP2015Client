cmake_minimum_required(VERSION 3.1)
project(ICP2015Client)

SET (CMAKE_CXX_FLAGS "-fPIC") # qt thingy

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(
    /home/gelidus/SOFTWARE/Qt5.2.0/5.2.0/gcc_64/include
)

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
target_link_libraries(ICP2015Client
    /home/gelidus/SOFTWARE/Qt5.2.0/5.2.0/gcc_64/lib/libQt5Core.so
    /home/gelidus/SOFTWARE/Qt5.2.0/5.2.0/gcc_64/lib/libQt5Network.so
    /home/gelidus/SOFTWARE/Qt5.2.0/5.2.0/gcc_64/lib/libQt5OpenGL.so
)