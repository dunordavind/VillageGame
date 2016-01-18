//
// Created by Petr Volkov on 13/01/2016.
//

#include <stddef.h>
#include <iostream>
#include "StateManager.h"
#include "Application.h"

namespace village {
    StateManager::StateManager() {

    }

    StateManager::~StateManager() {

    }

    void StateManager::addActiveState(State *state) {
        if(!states.empty()) {
            states.back()->pause();
        }
        states.push_back(state);
        state->init();
    }

    void StateManager::addInactiveState(State *state) {
        states.insert(states.begin(), state);
    }

    void StateManager::removeActiveState() {
        if(!states.empty()) {
            State *currentActiveState = states.back();

            currentActiveState->pause();
            currentActiveState->cleanup();
            states.pop_back();

            // maybe add a state to another empty stack (not implemented)
            // now it get's lost, but we cannot delete it here, because the method can be
            // called from the state that needs to delete itself from StateManager
            currentActiveState = nullptr ;
        } else {
            // quit with an error (not implemented)
        }
    }

    void StateManager::registerApplication(village::Application *app) {
        application = app;
    }



    State &StateManager::getActiveState() {
        return *states.back();
    }

    bool StateManager::isEmpty() {
        return states.empty();
    }
}