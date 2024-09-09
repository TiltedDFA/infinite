cmake_minimum_required(VERSION 3.29)
project(infinite C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_COMPILER gcc)
set(CMAKE_C_FLAGS_DEBUG  "-g3 -ggdb -O0 -Wall -Wextra -Wpedantic")
set(CMAKE_C_FLAGS_RELEASE "-O3 -static-libgcc -fno-exceptions --static -march=native -flto -flto-partition=one -ffat-lto-objects -funroll-loops -mtune=native" CACHE STRING "" FORCE)
set(CMAKE_EXE_LINKER_FLAGS "-flto=jobserver -static" CACHE STRING "" FORCE)
add_executable(infinite
        src/main.c
        src/Types.h
        src/Board.h
        src/Board.c
        src/Position.c
        src/Position.h
        src/Zobrist.h
        src/Zobrist.c
)
