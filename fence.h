#include <iostream>

using namespace std;

struct optimalSides {
    int sideA, sideB;
};

class Fence {
    int length;
    struct optimalSides sidesForMaxArea;

    public:
    Fence(int);
    struct optimalSides getSidesForMaxArea();
    void drawFence();
};