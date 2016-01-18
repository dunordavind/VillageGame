//
// Created by Petr Volkov on 12/01/2016.
//

#include "Application.h"
#include "SplashScreenState.h"
#include "MainMenuState.h"

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
        stateManager.addActiveState(new village::MainMenuState(*this));
        stateManager.addActiveState(new village::SplashScreenState(*this));

        // GameLoop if Running flag is still true
        gameLoop();

        return 0;
    }

    void Application::gameLoop() {
        while(isRunning()) {
            if(stateManager.isEmpty()) {
                quit();
            }
            State &currentState = stateManager.getActiveState();

            // process input
            currentState.handleEvents();

            // update state
            currentState.update();

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