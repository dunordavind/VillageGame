//
// Created by Petr Volkov on 13/01/2016.
//

#include "StateManager.h"

namespace village {
    StateManager::StateManager() {

    }

    void StateManager::addState(State *state) {
        if(!states.empty()) {
            states.back()->pause();
        }
        states.push_back(state);
    }

    void StateManager::registerApplication(village::Application *app) {
        application = app;
    }

    StateManager::~StateManager() {

    }

    State &StateManager::getState() {
        return *states.back();
    }

    bool StateManager::isEmpty() {
        return states.empty();
    }
}