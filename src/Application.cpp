//
// Created by Petr Volkov on 12/01/2016.
//

#include "Application.h"

namespace village {
    Application::Application() {

    }

    Application::~Application() {

    }

    int Application::run() {
        running = true;

        // GameLoop if Running flag is still true
        gameLoop();

        return 0;
    }

    void Application::gameLoop() {
        while(isRunning()) {
            // process input

            // update state

            // draw

            // display things

            // cleanup
        }
    }

    bool Application::isRunning() {
        return running;
    }

}