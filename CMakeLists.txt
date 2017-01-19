cmake_minimum_required(VERSION 3.5.1)

## Use the variable PROJECT_NAME for changing the target name
set( PROJECT_NAME "testThread" )
set (CMAKE_CXX_STANDARD 11)

## Set our project name
project(${PROJECT_NAME})

## Use all the *.cpp files we found under this folder for the project
FILE(GLOB SRCS "*.cpp" "*.c")
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)


## Define the executable
add_executable(${PROJECT_NAME} ${SRCS})
target_link_libraries(${PROJECT_NAME} Threads::Threads)
