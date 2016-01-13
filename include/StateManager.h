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
    private:
        std::vector<State *> states;

    };
}


#endif //VILLAGEGAME_STATEMANAGER_H
