cmake_minimum_required(VERSION 3.15)
project(gdi_algorithmen C)

set(CMAKE_C_STANDARD 99)

add_executable(gdi_algorithmen main.c quicksort.c quicksort.h bubblesort.c bubblesort.h mergesort.c mergesort.h main.h binary-search.c binary-search.h)