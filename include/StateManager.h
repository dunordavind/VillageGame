//
// Created by Petr Volkov on 13/01/2016.
//

#ifndef VILLAGEGAME_STATEMANAGER_H
#define VILLAGEGAME_STATEMANAGER_H

#include <vector>
#include "state.h"
#include "Application.h"


namespace village {
    class StateManager {
    public:
        StateManager();
        ~StateManager();

        void registerApplication(village::Application *);
        void addState(State *);
        State& getState();
        bool isEmpty();

        village::Application *application;

    private:
        std::vector<State *> states;
        StateManager(const StateManager&);
        StateManager& operator=(const StateManager&);
    };
}


#endif //VILLAGEGAME_STATEMANAGER_H
