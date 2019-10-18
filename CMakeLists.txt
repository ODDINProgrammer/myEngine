cmake_minimum_required(VERSION 2.6)
project(MYENGINE)

add_library(myEngine
	src/myengine/Core.cpp
	src/myengine/Core.h
	src/myengine/Entity.cpp
	src/myengine/Entity.h
	src/myengine/MyComponent.cpp
	src/myengine/MyComponent.h
)

target_link_libraries(myEngine SDL2 opengl32 glew32)

add_executable(game
  src/game/main.cpp
)