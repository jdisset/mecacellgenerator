cmake_minimum_required(VERSION 2.8)
project({{ Project }})

set(CMAKE_CXX_FLAGS "-O3 -g -std=c++11 -Wall -Wextra -Wundef -Wshadow -pedantic ")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

file(GLOB SRC
	"src/*.h"
	"src/*.hpp"
	"src/core/*.h"
	"src/core/*.hpp"
	"src/core/*.cpp"
	)

add_executable(console ${SRC} src/mainconsole.cpp)
target_link_libraries(console mecacell)

{% if viewerEnabled %}
set(CMAKE_AUTOMOC ON)
find_package(Qt5Core)
find_package(Qt5Widgets)
find_package(Qt5Gui)
find_package(Qt5Quick)
find_package(Qt5OpenGL)
add_executable(viewer ${SRC} src/mainviewer.cpp)
target_link_libraries(viewer mecacell)
target_link_libraries(viewer mecacellviewer)
qt5_use_modules(viewer Quick Core Gui OpenGL)
{% endif %}

