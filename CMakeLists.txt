cmake_minimum_required(VERSION 2.8.12)
project(qt_cpp_test_env)

# Specify the path to the qmake executable for Qt 4.8.7
SET(QT_QMAKE_EXECUTABLE "C:/Qt/qt4.8.7-msvc2015-x64/bin/qmake")

# Find the Qt4 libraries and includes
find_package(Qt4 COMPONENTS QtCore QtGui REQUIRED)
include(${QT_USE_FILE})

# Set up the source files
set(SOURCES
    main.cpp
)

# Set up the header files
set(HEADERS
    main.h
)


# Group the source and header files in the Visual Studio solution explorer
source_group("Sources" FILES ${SOURCES})
source_group("Headers" FILES ${HEADERS})

# Tell CMake to generate the moc files for the signal/slot operations
qt4_wrap_cpp(MOC_SOURCES ${HEADERS})


# Add the executable and link the Qt4 libraries
add_executable(QT_DEMO_TEST ${SOURCES} ${MOC_SOURCES})
target_link_libraries(QT_DEMO_TEST ${QT_LIBRARIES})

# Set the startup project for Visual Studio
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT QT_DEMO_TEST)
