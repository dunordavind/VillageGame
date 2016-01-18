//
// Created by petr_v on 14/01/2016.
//

#ifndef VILLAGEGAME_SPLASHSCREENSTATE_H
#define VILLAGEGAME_SPLASHSCREENSTATE_H

#include <iostream>
#include <State.h>

namespace village {
    class SplashScreenState : public State {
    public:
        SplashScreenState(village::Application &);

        virtual ~SplashScreenState();

        virtual void draw();

        virtual void init();

        virtual void pause() {};

        virtual void resume() {};

        virtual void handleEvents() {};

        virtual void update();

    protected:
        virtual void handleCleanup();

    private:
         float splashDelay;

    };
}


#endif //VILLAGEGAME_SPLASHSCREENSTATE_H
