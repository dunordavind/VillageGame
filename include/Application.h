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
    private:
        Application(const Application&);
        Application& operator=(const Application); //intentionally undefined
    };

}


#endif //VILLAGEGAME_APPLICATION_H
