//
// Created by Petr Volkov on 12/01/2016.
//

#include "Application.h"
#include "SplashScreenState.h"

namespace village {
    Application::Application() :
    stateManager() {

    }

    Application::~Application() {

    }

    int Application::run() {
        running = true;

        // Register app in the state manager
        stateManager.registerApplication(this);

        //init states
        village::SplashScreenState splashScreenState(*this);
        stateManager.addState(new village::SplashScreenState(*this));

        // GameLoop if Running flag is still true
        gameLoop();

        return 0;
    }

    void Application::gameLoop() {
        while(isRunning()) {
            if(stateManager.isEmpty()) {
                quit();
            }
            State &currentState = stateManager.getState();

            // process input
            currentState.handleEvents();

            // update state

            // draw
            currentState.draw();

            // display things

            // cleanup
        }
    }

    bool Application::isRunning() {
        return running;
    }

    void Application::quit() {
        running = false;
    }
}