//
// Created by Petr Volkov on 12/01/2016.
//

#include "Application.h"
#include "SplashScreenState.h"
#include "MainMenuState.h"

namespace village {

    Application* Application::application = NULL; // refactor this global to singleton

    Application::Application(std::string title) :
    title(title),
    videoMode(DEFAULT_VIDEO_WIDTH, DEFAULT_VIDEO_HEIGHT, DEFAULT_VIDEO_BPP),
    window(),
    contextSettings(),
    updateRate((1000.0f / 20.0f)),
    running(false),
    stateManager(),
    assetManager() {

    }

    Application::~Application() {
        running = false;
    }

    int Application::run() {
        running = true;

        // Register app in the state manager
        stateManager.registerApplication(this);

        //init states
        stateManager.addActiveState(new village::MainMenuState(*this));
        stateManager.addActiveState(new village::SplashScreenState(*this));

        //init renderer
        initRenderer();

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

            // draw stuff
            currentState.draw();

            // display things
            window.display();

            // cleanup
            // stateManager.cleanup - not implemented yet
        }
    }

    bool Application::isRunning() {
        return running;
    }

    void Application::quit() {
        running = false;
    }

    void Application::initRenderer() {
        // implement all the options from the config,
        // needs config first
        // only default window creation for now

        window.create(videoMode, title);
    }

    Application *Application::getApp() {
        return application;
    }
}