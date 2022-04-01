#include <iostream>
#include "fence.h"

using namespace std;

Fence::Fence(int lenght) {
    this->length = lenght;
}

//Lenght of the fence is: 2*x + y = l, so y = l-2*x, so area is a * b = x*(l-2x) = -2x^2 + l*x
//Area of the fence can be described as parabola where its max is localized in the vertex of the parabola.
//vx= -b/2*a, where a is -2, and b is l (length), where vx is x coordinate of the vertex and represents one side of the fence.
//Counting on int will cut the number to the closest lower integer, what is needed, because of the negative 'a' param.  
//Second side of the fence will be: y = l-2*x, where x is the first side.
struct optimalSides Fence::getSidesForMaxArea() {
    int vertex;
    
    if (this->length <= 0) {
        throw invalid_argument("Length of the fence cannot be negative or zero");
    }

    vertex = this->length/4;

    struct optimalSides sides;
    sides.sideA = vertex;
    sides.sideB = this->length - 2 * vertex;

    return sides;
}

void Fence::drawFence() {
//TODO: implement a function to draw proportions of the optimal fence in console using dots or specials chars.
}