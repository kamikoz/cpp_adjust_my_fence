#include <iostream>
#include "fence.h"
#include <string>

int main() {
    std::string userChoice;
    std::cout << std::endl << "Welcome to Adjust My Fence!" << std::endl;

    do {
        std::cout << "Type 'RUN' to start: ";
        std::getline(std::cin, userChoice);
    } while(userChoice != "RUN");

    int fenceLength = Fence::getUserConsoleValidLength();

    try
    {
        Fence fence(fenceLength);
        fence.optimizeForMaxArea();
        std::cout << fence.getFenceDraw();
        std::cout << std::endl << fence.getResultOfOptimizingForMaxArea();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << std::endl << "Thank you for using Adjust My Fence. Bye!" << std::endl;
    return 0;
}
