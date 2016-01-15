//
// Created by petr_v on 15/01/2016.
//

#include "MainMenuState.h"
#include <iostream>

namespace village {

    MainMenuState::MainMenuState(Application &application) :
    State(application) {

    }

    void MainMenuState::draw() {
        std::cout << "Drawing main menu " << std::endl;
    }
}