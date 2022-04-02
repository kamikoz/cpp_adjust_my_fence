#include <iostream>
#include "fence.h"

int main() {
    int fenceLength = Fence::getUserConsoleValidLength();
    Fence fence(fenceLength);
    fence.optimizeForMaxArea();
    std::cout << fence.getResultOfOptimizingForMaxArea();

    return 0;
}
