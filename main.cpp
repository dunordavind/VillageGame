#include <iostream>
#include <SFML/Graphics.hpp>
#include "Application.h"

using namespace std;

int main() {
    //initialize an application class
    village::Application *a = new(std::nothrow) village::Application();

    int result = a->run();

    //delete application class
    delete(a);
    a = nullptr;

    return 0;
}