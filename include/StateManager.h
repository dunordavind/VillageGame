//
// Created by Petr Volkov on 13/01/2016.
//

#ifndef VILLAGEGAME_STATEMANAGER_H
#define VILLAGEGAME_STATEMANAGER_H

#include <vector>
#include "state.h"


namespace village {
    class Application; // forward declare application class

    class StateManager {
    public:
        StateManager();
        ~StateManager();

        void registerApplication(village::Application *);
        void addActiveState(State *);
        void addInactiveState(State *);
        void removeActiveState();
        State &getActiveState();

        bool isEmpty();

        village::Application *application;

    private:
        std::vector<State *> states;
        StateManager(const StateManager&);
        StateManager& operator=(const StateManager&);
    };
}


#endif //VILLAGEGAME_STATEMANAGER_H
