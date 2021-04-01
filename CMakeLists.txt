cmake_minimum_required(VERSION 3.17)
project(SDL_first_window)
set(CMAKE_CXX_STANDARD 20)

set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake" )

find_package(SDL2       REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf   REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_net   REQUIRED)

include_directories( ${SDL2_INCLUDE_DIR} )
include_directories( ${SDL2_IMAGE_INCLUDE_DIR} )
include_directories( ${SDL2_MIXER_INCLUDE_DIR} )
include_directories( ${SDL2_TTF_INCLUDE_DIR} )
include_directories( ${SDL2_NET_INCLUDE_DIR} )

add_executable( ${PROJECT_NAME} main.cpp )

#target_link_libraries( ${PROJECT_NAME} -lmingw32 )
target_link_libraries( ${PROJECT_NAME} ${SDL2_LIBRARY} )
target_link_libraries( ${PROJECT_NAME} ${SDL2_IMAGE_LIBRARY} )
target_link_libraries( ${PROJECT_NAME} ${SDL2_MIXER_LIBRARY} )
target_link_libraries( ${PROJECT_NAME} ${SDL2_TTF_LIBRARY} )
target_link_libraries( ${PROJECT_NAME} ${SDL2_NET_LIBRARY} )
