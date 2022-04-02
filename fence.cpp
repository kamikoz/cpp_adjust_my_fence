#include <iostream>
#include "fence.h"
#include <string>
#include <math.h>

Fence::Fence(int lenght) {
    if (length < 3) {
        throw std::invalid_argument("Length of the fence cannot be less than 3");
    }

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

std::string Fence::getFenceDraw() {
    char rightTopCorner = 187;
    char rightBottomCorner = 188;

    char leftTopCorner = 201;
    char leftBottomCorner = 200;

    char verticalLine = 186;
    char horizontalLine = 205;

    std::string fenceDraw = "\n";
    struct sides sides = this->getSides();

    if (!sides.isOptimizedForMaxArea) {
        return "The fence has been not optimized for max area.";
    }

    int sizeX = this->getSides().sideX;
    int sizeY = this->getSides().sideY;

    //To draw a very small fence
    if (sizeY <= 2 || sizeX <= 2) {
        sizeY *= 4;
        sizeX *= 4;
    }

    //to draw a very big fence
    if (sizeY > 20) {
        float proportion = (float)sizeY / 20;
        sizeY = 20;
        sizeX = round(sizeX / proportion);
    }

    int doubleSizeX = 2 * sizeX;

    //Loop (i) decides how many raws program draws and how many ║ are there (this is sizeY of the fence).
    //Loop (j) decides how many columns program draws and how many ═ or " " are there (this is sizeX of the fence). 
    //Because ║ takes around 2 more space than ═, we need to duplicate loop (j) iterator.
    for (int i = 0; i < sizeY; i++)
    {
        for (int j = 0; j < doubleSizeX; j++){
            if (j == doubleSizeX - 1) {
                if (i == 0) {
                    fenceDraw += rightTopCorner;
                    fenceDraw += "\n";
                } else if (i == ceil(sizeY / 2)) {
                    fenceDraw += verticalLine;
                    fenceDraw += " b = " + std::to_string(this->getSides().sideY);
                    fenceDraw += "\n";
                } else if (i == sizeY - 1) {
                    fenceDraw += rightBottomCorner;
                    fenceDraw += "\n";
                } else {
                    fenceDraw += verticalLine;
                    fenceDraw += "\n";
                }
            } else {
                if (i == 0 || i == sizeY - 1) {
                    fenceDraw += horizontalLine;
                } else {
                    fenceDraw += " ";
                }
            }
        }
    }

    fenceDraw += "a = " + std::to_string(this->getSides().sideX) + "\n";
    return fenceDraw;
}

std::string Fence::getResultOfOptimizingForMaxArea() {
    if (!this->sides.isOptimizedForMaxArea) {
        return "\nThe fence has been not optimized for max area.";
    } else {
        return "\nThe fence has been optimized for max area and its sides are: a = " +  
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
            
            //check if number is not integer (fraction)
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