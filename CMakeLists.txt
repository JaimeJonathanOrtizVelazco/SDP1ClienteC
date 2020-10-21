cmake_minimum_required(VERSION 3.17)
project(SDT1Cliente C)

set(CMAKE_C_STANDARD 99)

add_executable(SDT1Cliente main.c Socket.c Socket.h Socker_Cliente.c Socker_Cliente.h)