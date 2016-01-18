//
// Created by Petr Volkov on 13/01/2016.
//

#include <iostream>
#include "State.h"
#include "Application.h"

namespace village {

    State::State(village::Application &application) :
    elapsedTime(0.0f),
    initialized(false),
    markedForCleanup(false),
    application(application) {

    }

    State::~State() {
        std::cout << "State desctructor called" << std::endl;
    }

    void State::init() {
        if(!initialized) {
            initialized = true;
            elapsedTime = 0.0f;
            elapsedClock.restart();
        }
    }

    float State::getElapsedTime() const {
        float result = elapsedClock.getElapsedTime().asSeconds();

        if(!initialized) {
            result = elapsedTime;
        }
        return result;
    }

    bool State::isInitialized() const {
        return initialized;
    }

    void State::cleanup() {
        if(markedForCleanup) {
            handleCleanup();
            markedForCleanup = false;
        }
    }
}