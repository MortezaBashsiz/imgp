cmake_minimum_required(VERSION 2.8)
project( face )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
file(GLOB sources *.hpp *.cpp) 
add_executable( face ${sources} )
target_link_libraries( face ${OpenCV_LIBS} ) 