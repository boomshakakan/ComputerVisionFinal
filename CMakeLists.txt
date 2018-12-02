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
include_directories( ${TESSERACT_INCLUDE_DIRS} )
include_directories( ${LEPTONICA_INCLUDE_DIRS} )

link_directories( ${TESSERACT_LIBRARY_DIRS} )
link_directories( ${LEPTONICA_LIBRARY_DIRS} )

find_package( OpenCV REQUIRED )
find_package( Tesseract REQUIRED )

add_executable( imgProcess src/imgProcess.cpp )
target_link_libraries( imgProcess ${OpenCV_LIBS} )
target_link_libraries( imgProcess ${TESSERACT_LIBRARIES}} )
target_link_libraries( imgProcess ${LEPTONICA_LIBRARIES} )