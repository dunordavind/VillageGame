//
// Created by Petr Volkov on 12/01/2016.
//

#ifndef VILLAGEGAME_APPLICATION_H
#define VILLAGEGAME_APPLICATION_H

#include <string>
#include <SFML/Window/VideoMode.hpp>
#include "StateManager.h"

namespace village {
    class Application {
    public:
        // constants
        static const unsigned int DEFAULT_VIDEO_WIDTH = 800;
        static const unsigned int DEFAULT_VIDEO_HEIGHT = 600;
        static const unsigned int DEFAULT_VIDEO_BPP = 32;

        // variables
        std::string title;
        sf::VideoMode videoMode;

        int run();
        bool isRunning();

        void quit();

        village::StateManager stateManager;

        Application(std::string);
        ~Application();
    private:
        bool running = false;
        void gameLoop();

        Application(const Application&);
        Application& operator=(const Application); //intentionally undefined

    };
}


#endif //VILLAGEGAME_APPLICATION_H
