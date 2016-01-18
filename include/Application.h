//
// Created by Petr Volkov on 12/01/2016.
//

#ifndef VILLAGEGAME_APPLICATION_H
#define VILLAGEGAME_APPLICATION_H

#include <string>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
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
        sf::RenderWindow window;
        sf::ContextSettings contextSettings;


        int run();
        bool isRunning();

        void quit();

        village::StateManager stateManager;

        Application(std::string);
        ~Application();
    private:
        float updateRate;
        bool running;
        void gameLoop();
        void initRenderer();

        Application(const Application&);
        Application& operator=(const Application); //intentionally undefined

    };
}


#endif //VILLAGEGAME_APPLICATION_H
