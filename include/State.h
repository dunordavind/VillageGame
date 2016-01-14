//
// Created by Petr Volkov on 13/01/2016.
//

#ifndef VILLAGEGAME_STATE_H
#define VILLAGEGAME_STATE_H



namespace village {
    class Application;

    class State {
    public:

        State(village::Application &application) { }

        virtual ~State() {};

        // init
        virtual void init() = 0;

        // cleanup
        virtual void cleanup() = 0;

        // pause
        virtual void pause() = 0;

        // resume
        virtual void resume() = 0;

        // handle events
        virtual void handleEvents() = 0;

        //
        virtual void update() = 0;

        virtual void draw() = 0;
    };
}


#endif //VILLAGEGAME_STATE_H
