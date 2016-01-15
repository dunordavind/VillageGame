//
// Created by Petr Volkov on 13/01/2016.
//

#include "StateManager.h"
#include "Application.h"

namespace village {
    StateManager::StateManager() {

    }

    void StateManager::addActiveState(State *state) {
        if(!states.empty()) {
            states.back()->pause();
        }
        states.push_back(state);
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

            // maybe add a state to another stack (not implemented)

            currentActiveState = 0;
        } else {
            // quit with an error (not implemented)
        }
    }

    void StateManager::registerApplication(village::Application *app) {
        application = app;
    }

    StateManager::~StateManager() {

    }

    State &StateManager::getActiveState() {
        return *states.back();
    }

    bool StateManager::isEmpty() {
        return states.empty();
    }
}