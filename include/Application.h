//
// Created by Petr Volkov on 12/01/2016.
//

#ifndef VILLAGEGAME_APPLICATION_H
#define VILLAGEGAME_APPLICATION_H

namespace village {
    class Application {
    public:
        Application();
        ~Application();

        int run();
        bool isRunning();
    private:
        bool running = false;
        void gameLoop();

        Application(const Application&);
        Application& operator=(const Application); //intentionally undefined

    };

}


#endif //VILLAGEGAME_APPLICATION_H
