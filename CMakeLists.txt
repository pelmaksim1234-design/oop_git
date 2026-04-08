cmake_minimum_required(VERSION 3.16)
project(oop_git)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Лабораторна 2 ---
add_executable(lab2
        labs2-4/main.cpp
        labs2-4/classes/Inventory.cpp
        labs2-4/classes/Character.cpp
        labs2-4/classes/MainHero.cpp
        labs2-4/classes/WarriorHero.cpp
        labs2-4/classes/Npc.cpp
        labs2-4/classes/Villager.cpp
        labs2-4/classes/Enemy.cpp
        labs2-4/classes/BossEnemy.cpp
)

target_include_directories(lab2 PRIVATE
        labs2-4/classes
)

get_filename_component(MINGW_BIN_DIR "${CMAKE_CXX_COMPILER}" DIRECTORY)
foreach (runtime_dll IN ITEMS libstdc++-6.dll libgcc_s_seh-1.dll libwinpthread-1.dll)
    if (EXISTS "${MINGW_BIN_DIR}/${runtime_dll}")
        add_custom_command(TARGET lab2 POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                "${MINGW_BIN_DIR}/${runtime_dll}"
                "$<TARGET_FILE_DIR:lab2>"
        )
    endif ()
endforeach ()

# --- Лабораторна 3 ---
# Тут ми збираємо car.cpp (де main) та made.cpp (де логіка класу)
if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/labs3/car.cpp" AND
    EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/labs3/made.cpp")
    add_executable(lab3
            labs3/car.cpp
            labs3/made.cpp
    )
endif ()

# --- Лабораторна 4 ---
# Тут ми збираємо cars.cpp (де main) та vehicle.cpp (де логіка класів)
if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/labs4/cars.cpp" AND
    EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/labs4/vehicle.cpp")
    add_executable(lab4
            labs4/cars.cpp
            labs4/vehicle.cpp
    )
endif ()
