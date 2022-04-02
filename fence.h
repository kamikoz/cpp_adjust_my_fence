struct sides {
    int sideX, sideY;
    bool isOptimizedForMaxArea;
};

class Fence {
    int length;
    struct sides sides;

    public:
    Fence(int);
    struct sides getSides();
    void optimizeForMaxArea();
    void drawFence();
    std::string getResultOfOptimizingForMaxArea();

    static int getUserConsoleValidLength();
};