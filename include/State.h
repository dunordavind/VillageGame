//
// Created by Petr Volkov on 13/01/2016.
//

#ifndef VILLAGEGAME_STATE_H
#define VILLAGEGAME_STATE_H


#include <SFML/System/Clock.hpp>

namespace village {
    class Application;

    class State {
    public:
        State(village::Application &application);

        virtual ~State();

        // init
        virtual void init();

        // cleanup
        virtual void cleanup();

        // pause
        virtual void pause() = 0;

        // resume
        virtual void resume() = 0;

        // handle events
        virtual void handleEvents() = 0;

        //
        virtual void update() = 0;

        virtual void draw() = 0;

        float getElapsedTime() const;

        bool isInitialized() const;

    protected:
        virtual void handleCleanup() = 0;

        Application &application;

    private:
        sf::Clock elapsedClock;

        float elapsedTime;

        bool initialized;

        bool markedForCleanup;

    };
}


#endif //VILLAGEGAME_STATE_H
