#include <iostream>

using namespace std;

struct optimalSides {
    int sideA, sideB;
};

class Fence {
    int length;
    struct optimalSides sidesForMaxField;

    public:
    Fence(int);
    struct optimalSides getSidesForMaxField();
    void drawFence();

    private:
    int countField();
};