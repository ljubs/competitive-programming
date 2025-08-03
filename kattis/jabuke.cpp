#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    int xA, yA, xB, yB, xC, yC;
    std::cin >> xA >> yA;
    std::cin >> xB >> yB;
    std::cin >> xC >> yC;

    double areaOfTriangle = std::abs(xA * (yB - yC) + xB * (yC - yA) + xC * (yA - yB)) / 2.0;
    std::cout << std::fixed << std::setprecision(1) << areaOfTriangle << std::endl;

    int numberOfTrees;
    std::cin >> numberOfTrees;

    int treesInside = 0;
    for (int i = 0; i < numberOfTrees; i++) {
        int x, y;
        std::cin >> x >> y;

        double A1 = std::abs(x * (yB - yC) + xB * (yC - y) + xC * (y - yB)) / 2.0;
        double A2 = std::abs(xA * (y - yC) + x * (yC - yA) + xC * (yA - y)) / 2.0;
        double A3 = std::abs(xA * (yB - y) + xB * (y - yA) + x * (yA - yB)) / 2.0;

        if (A1 + A2 + A3 == areaOfTriangle)
            treesInside++;
    }

    std::cout << treesInside << std::endl;
}