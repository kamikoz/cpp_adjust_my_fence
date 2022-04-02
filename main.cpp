#include <iostream>
#include "fence.h"

using namespace std;

int main() {
    int fenceLength = Fence::getUserConsoleValidLength();
    Fence fence(fenceLength);
    fence.optimizeForMaxArea();
    cout << fence.getResultOfOptimizingForMaxArea();

    return 0;
}
