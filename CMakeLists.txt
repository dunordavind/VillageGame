cmake_minimum_required(VERSION 3.3)
project(VillageGame)

include_directories(include)
include_directories(include/states)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp
        src/Application.cpp include/Application.h
        src/StateManager.cpp include/StateManager.h
        src/State.cpp include/State.h
        src/states/SplashScreenState.cpp include/states/SplashScreenState.h)
add_executable(VillageGame ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(SFML_ROOT "C:/Users/petr_v/Documents/Libraries/SFML-2.3.2")
endif()

find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(VillageGame ${SFML_LIBRARIES})
endif()