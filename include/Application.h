//
// Created by Petr Volkov on 12/01/2016.
//

#ifndef VILLAGEGAME_APPLICATION_H
#define VILLAGEGAME_APPLICATION_H

#include "StateManager.h"

namespace village {
    class Application {
    public:
        Application();
        ~Application();

        int run();
        bool isRunning();

        void quit();

        village::StateManager stateManager;
    private:
        bool running = false;
        void gameLoop();

        Application(const Application&);
        Application& operator=(const Application); //intentionally undefined

    };
}


#endif //VILLAGEGAME_APPLICATION_H
