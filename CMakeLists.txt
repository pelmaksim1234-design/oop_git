cmake_minimum_required(VERSION 3.30)
project(oop_git)

set(CMAKE_CXX_STANDARD 17)

# КРИТИЧНИЙ МОМЕНТ:
# Тобі потрібно перелічити ВСІ .cpp файли, які ти створив.
# Якщо файли лежать у папці labs3, додай назву папки перед файлом.

add_executable(oop_git
        labs2/main.cpp
        labs2/Characters1.h
        labs2/Characters1.cpp
        labs3/carmain.cpp
        labs3/made.cpp
        labs3/made.h
)