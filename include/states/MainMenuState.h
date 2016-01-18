//
// Created by petr_v on 15/01/2016.
//

#ifndef VILLAGEGAME_MAINMENUSTATE_H
#define VILLAGEGAME_MAINMENUSTATE_H


#include <State.h>

namespace village {
    class MainMenuState : public State {
    public:
        MainMenuState(village::Application &);

        virtual void draw();

        virtual void init();

        virtual void pause() {};

        virtual void resume() {};

        virtual void handleEvents() {};

        virtual void update();
    protected:
        virtual void handleCleanup();
    };
}


#endif //VILLAGEGAME_MAINMENUSTATE_H
