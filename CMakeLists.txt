cmake_minimum_required(VERSION 3.16)
project(oop_git)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LABS_2_5_SOURCES
        labs2_5/classes/Inventory.cpp
        labs2_5/classes/Character.cpp
        labs2_5/classes/MainHero.cpp
        labs2_5/classes/WarriorHero.cpp
        labs2_5/classes/Npc.cpp
        labs2_5/classes/Villager.cpp
        labs2_5/classes/Enemy.cpp
        labs2_5/classes/BossEnemy.cpp
        labs2_5/classes/GameRepository.cpp
        labs2_5/classes/GameApp.cpp
)

add_executable(lab5
        labs2_5/main.cpp
        ${LABS_2_5_SOURCES}
)

target_include_directories(lab5 PRIVATE
        labs2_5/classes
)

add_executable(lab6
        labs2_5/main.cpp
        ${LABS_2_5_SOURCES}
)

target_include_directories(lab6 PRIVATE
        labs2_5/classes
)

get_filename_component(MINGW_BIN_DIR "${CMAKE_CXX_COMPILER}" DIRECTORY)
foreach (runtime_dll IN ITEMS libstdc++-6.dll libgcc_s_seh-1.dll libwinpthread-1.dll)
    if (EXISTS "${MINGW_BIN_DIR}/${runtime_dll}")
        foreach (target_name IN ITEMS lab5 lab6)
            add_custom_command(TARGET ${target_name} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    "${MINGW_BIN_DIR}/${runtime_dll}"
                    "$<TARGET_FILE_DIR:${target_name}>"
            )
        endforeach ()
    endif ()
endforeach ()

if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/labs3/car.cpp" AND
    EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/labs3/made.cpp")
    add_executable(lab3
            labs3/car.cpp
            labs3/made.cpp
    )
endif ()

if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/labs4/cars.cpp" AND
    EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/labs4/vehicle.cpp")
    add_executable(lab4
            labs4/cars.cpp
            labs4/vehicle.cpp
    )
endif ()
