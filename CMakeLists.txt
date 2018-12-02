if (UNIX)
    message(status "Setting GCC flags")
    set(CMAKE_CPP_FLAGS "${CMAKE_CPP_FLAGS} -fexceptions -g -Wall")
else()
    message(status "Setting MSVC flags")
    set(CMAKE_CPP_FLAGS "${CMAKE_CPP_FLAGS} /EHc-")
endif()
message(status "** CMAKE_CPP_FLAGS: ${CMAKE_CPP_FLAGS}")

cmake_minimum_required(VERSION 2.8)
project( imgProcess )

include_directories( src )

find_package( OpenCV REQUIRED )

add_executable( imgProcess src/imgProcess.cpp )
target_link_libraries( imgProcess ${OpenCV_LIBS} )