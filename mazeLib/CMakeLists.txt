add_library(mazeLib src/Coordinate.cpp src/Maze.cpp)
#add_library(mazeLib src/Maze.cpp)

message("${CMAKE_CURRENT_SOURCE_DIR} is the current source")

target_include_directories(mazeLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)