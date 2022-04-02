#include <iostream>
#include "fence.h"
#include <string>
#include <math.h>

Fence::Fence(int lenght) {
    this->length = lenght;
}

//Lenght of the fence where one side is the infinite wall we can describe as: 2*x + y = l, so y = l-2*x.
//Area of this fence will be: x*(l-2x) = -2x^2 + l*x
//So area of the fence is parabola where its max is localized in the vertex of the parabola.
//Formula for the vertex of the parabola: vx= -b/2*a, where a is -2, and b is l (length), 
//This is x coordinate of the vertex and represents first side of the fence (the one that is double).
//The result of dividing int numbers will be the closest lower integer. 
//what is needed, because of the expectations and negative 'a' param of the parabola (it decreases after exceeds the vertex)  
//Second side of the fence will be: y = l-2*x, where x is the first side.
void Fence::optimizeForMaxArea() {
    if (this->length < 3) {
        throw std::invalid_argument("Length of the fence cannot be less than 3");
    }

    if (this->length == 3) {
        this->sides.sideX = 1;
        this->sides.sideY = 1;
    } else {
        this->sides.sideX = this->length/4;
        this->sides.sideY = this->length - 2 * this->sides.sideX;
    }
    
    this->sides.isOptimizedForMaxArea = true;
}

struct sides Fence::getSides() {
    return this->sides;
}

void Fence::drawFence() {
//TODO: implement a function to draw proportions of the optimal fence in console using dots or specials chars.
}

std::string Fence::getResultOfOptimizingForMaxArea() {
    if (!this->sides.isOptimizedForMaxArea) {
        return "The fence has been not optimized for max area.";
    } else {
        return "The fence has been optimized for max area and its sides are: a = " +  
        std::to_string(this->getSides().sideX) + " and b = " + std::to_string(this->getSides().sideY);
    }
}

int Fence::getUserConsoleValidLength() {
    float number;
    bool isInt;
    std::string value;

    std::cout << std::endl << "Enter the length of the fence (must be integer): ";

    do {
        try {
            std::getline(std::cin, value);
            number = stof(value);

            if (number < 3) {
                throw std::invalid_argument("length cannot be less than 3");
            }
            
            //check if number is float
            float roundNumber = floor(number);
            if (roundNumber != number) {
                throw std::invalid_argument("length cannot be a fraction");
            } else {
                isInt = true;
                break;
            }
        }
        catch (std::invalid_argument& e) { 
            std::cout << "ERROR: please enter a integer number: " << e.what() << ": ";
        }
    } while (!isInt);
    
    std::cout << std::endl << "Length of the fence is: " << number << std::endl;
    return static_cast<int>(number);
}