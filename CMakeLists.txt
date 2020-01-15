cmake_minimum_required(VERSION 2.6)
project(Daniil_Engine)

include_directories(
src
)

add_library(legendaryEngine
 src/legendaryEngine/lG.cpp
 src/legendaryEngine/Core.cpp
 src/legendaryEngine/Component.cpp
 src/legendaryEngine/Keyboard.cpp
 src/legendaryEngine/Environment.cpp
 src/legendaryEngine/Entity.cpp
 src/legendaryEngine/Screen.cpp
 src/legendaryEngine/Core.h
 src/legendaryEngine/lG.h
 src/legendaryEngine/Component.h
 src/legendaryEngine/Keyboard.h
 src/legendaryEngine/Environment.h
 src/legendaryEngine/Entity.h
 src/legendaryEngine/Screen.h)

add_library(rend
src/rend/Exception.cpp
src/rend/Context.cpp
src/rend/Texture.cpp
src/rend/RenderTexture.cpp
src/rend/Shader.cpp
src/rend/Buffer.cpp
src/rend/Mesh.cpp
src/rend/Util.cpp
)

if (MSVC)
	target_link_libraries(rend glew32 opengl32)
else()
	target_link_libraries(rend GLEW GL)
endif()
target_link_libraries(legendaryEngine rend SDL2)

add_executable(game
 src/game/main.cpp
 src/game/tempComponent.h
 src/game/tempComponent.cpp)

target_link_libraries(game
 legendaryEngine)