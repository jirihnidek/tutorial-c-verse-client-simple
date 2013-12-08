# Minimal version of CMake
cmake_minimum_required (VERSION 2.6)

set (CMAKE_C_FLAGS "-D_REETRANT -ggdb -O0")

# Pthread is *prefered* (only supported) thread library
set (CMAKE_THREAD_PREFER_PTHREAD)

# Try to find required packages
find_package (Threads REQUIRED)

# Try to find OpenSSL library
find_package (OpenSSL REQUIRED)

# Try to search current direcotry for find cmake modules
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}")

# Try to find Verse library
find_package (Verse REQUIRED)

# Directories with required .h files
include_directories (${OPENSSL_INCLUDE_DIR} ${VERSE_INCLUDE_DIR})

# Libraries linked with verse client
set ( verse_client_libs ${CMAKE_THREAD_LIBS_INIT} ${OPENSSL_LIBRARIES} ${VERSE_LIBRARIES})

set (src verse_client.c)

add_executable(verse_client ${src})
target_link_libraries (verse_client ${verse_client_libs})
