//
// Created by Petr Volkov on 13/01/2016.
//

#include "StateManager.h"

namespace village {
    StateManager::StateManager() {

    }

    void StateManager::addState(State *state) {

    }

    StateManager::~StateManager() {

    }

    State &StateManager::getState() {
        return *states.back();
    }
}