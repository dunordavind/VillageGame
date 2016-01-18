cmake_minimum_required(VERSION 3.3)
project(VillageGame)

include_directories(include)
include_directories(include/states)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp
        src/Application.cpp include/Application.h
        src/StateManager.cpp include/StateManager.h
        src/State.cpp include/State.h
        src/states/SplashScreenState.cpp include/states/SplashScreenState.h
        src/states/MainMenuState.cpp include/states/MainMenuState.h)
add_executable(VillageGame ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(SFML_ROOT "C:/Users/petr_v/Documents/Libraries/Build")
endif()

set(SFML_STATIC_LIBRARIES ON)
find_package(SFML 2 REQUIRED graphics window network audio system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(VillageGame ${SFML_LIBRARIES})
    target_link_libraries(VillageGame ${SFML_DEPENDENCIES})
else()
    message(WARNING "SFML NOT FOUND")
endif()