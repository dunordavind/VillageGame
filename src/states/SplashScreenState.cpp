//
// Created by petr_v on 14/01/2016.
//

#include <Application.h>
#include "SplashScreenState.h"

namespace village {
    SplashScreenState::SplashScreenState(Application &application) :
    village::State(application),
    splashDelay(0.02) {
    }

    SplashScreenState::~SplashScreenState() {
        std::cout << "Splash menu screen desctructor called" << std::endl;
    }

    void SplashScreenState::draw() {
        std::cout << "Drawing splash screen" << std::endl;
    };


    void SplashScreenState::update() {
        if(getElapsedTime() > splashDelay) {
            application.stateManager.removeActiveState();
        }
    }

    void SplashScreenState::init() {
        State::init();
    }

    void SplashScreenState::handleCleanup() {

    }
}