//
// Created by Petr Volkov on 13/01/2016.
//

#ifndef VILLAGEGAME_STATEMANAGER_H
#define VILLAGEGAME_STATEMANAGER_H

#include <vector>
#include "state.h"


namespace village {
    class StateManager {
    public:
        StateManager();
        ~StateManager();
        void addState(State *);
        State& getState();
    private:
        std::vector<State *> states;
        StateManager(const StateManager&);
        StateManager& operator=(const StateManager&);
    };
}


#endif //VILLAGEGAME_STATEMANAGER_H
