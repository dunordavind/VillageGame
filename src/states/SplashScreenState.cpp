//
// Created by petr_v on 14/01/2016.
//

#include "SplashScreenState.h"

namespace village {
    SplashScreenState::SplashScreenState(Application &application) :
    village::State(application){
    }
    void SplashScreenState::draw() {
        std::cout << "Drawing splash screen" << std::endl;
    };
}