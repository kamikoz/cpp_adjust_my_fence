#include <iostream>
#include "fence.h"

using namespace std;

int main() {
    Fence fence1(30);
    cout<<fence1.getSidesForMaxArea().sideA<<" drugi: " <<fence1.getSidesForMaxArea().sideB;
    return 0;
}