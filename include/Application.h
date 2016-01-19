//
// Created by Petr Volkov on 12/01/2016.
//

#ifndef VILLAGEGAME_APPLICATION_H
#define VILLAGEGAME_APPLICATION_H

#include <string>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "StateManager.h"
#include "AssetManager.h"

namespace village {
    class Application {
    public:
        Application(std::string);

        ~Application();

        static Application *getApp();

        // constants
        static const unsigned int DEFAULT_VIDEO_WIDTH = 800;
        static const unsigned int DEFAULT_VIDEO_HEIGHT = 600;
        static const unsigned int DEFAULT_VIDEO_BPP = 32;

        // variables
        std::string title;

        sf::VideoMode videoMode;

        sf::RenderWindow window;

        sf::ContextSettings contextSettings;

        AssetManager assetManager;

        village::StateManager stateManager;

        //methods
        int run();

        bool isRunning();

        void quit();


    private:
        static Application* application;



        float updateRate;

        bool running;

        void gameLoop();

        void initRenderer();

        Application(const Application&);

        Application& operator=(const Application); //intentionally undefined

    };
}


#endif //VILLAGEGAME_APPLICATION_H
