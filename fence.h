struct sides {
    int sideX, sideY;
};

class Fence {
    int length;
    struct sides sides;
    bool isOptimizedForMaxArea;

    public:
    Fence(int);
    struct sides getSides();
    void optimizeForMaxArea();
    void drawFence();
    std::string getResultOfOptimizingForMaxArea();

    static int getUserConsoleValidLength();
};