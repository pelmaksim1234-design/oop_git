cmake_minimum_required(VERSION 3.16)
project(oop_git)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Лабораторна 2 ---
add_executable(lab2
        labs2/main.cpp
        labs2/Characters1.cpp
)

# --- Лабораторна 3 ---
# Тут ми збираємо car.cpp (де main) та made.cpp (де логіка класу)
add_executable(lab3
        labs3/car.cpp
        labs3/made.cpp
)

# --- Лабораторна 4 ---
# Тут ми збираємо cars.cpp (де main) та vehicle.cpp (де логіка класів)
add_executable(lab4
        labs4/cars.cpp
        labs4/vehicle.cpp
)
