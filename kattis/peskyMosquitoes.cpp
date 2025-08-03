#include <iostream>
#include <vector>
#include <cmath>

double calculateDistance(double x1, double y1, double x2, double y2) {
    return std::abs(sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}

std::pair<double, double> getNormalVector(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    
    double normalX = -dy;
    double normalY = dx;
    
    double length = std::sqrt(normalX * normalX + normalY * normalY);
    normalX /= length;
    normalY /= length;
    
    return {normalX, normalY};
}

int maxMosquitoes(std::vector<std::pair<double, double>> coordinates, double diameterOfBowl) {
    int n = coordinates.size();
    int maxCount = 0;
    double radius = diameterOfBowl / 2.0;

    for (int i = 0; i < n; i++) {
        double centerX, centerY;
        std::tie(centerX, centerY) = coordinates[i];
        int count = 0;
        for (int j = 0; j < n; j++) {
            double x, y;
            std::tie(x, y) = coordinates[j];
            if (calculateDistance(centerX, centerY, x, y) <= radius)
                count++;
            maxCount = std::max(maxCount, count);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double x1, y1, x2, y2;
            std::tie(x1, y1) = coordinates[i];
            std::tie(x2, y2) = coordinates[j];
            double distanceBetween = calculateDistance(x1, y1, x2, y2);
            if (distanceBetween > diameterOfBowl)
                continue;
            double middleX = (x1 + x2) / 2.0;
            double middleY = (y1 + y2) / 2.0;
            if (distanceBetween == diameterOfBowl) {
                int count = 0;
                for (int k = 0; k < n; k++) {
                    double x3, y3;
                    std::tie(x3, y3) = coordinates[k];
                    if (calculateDistance(middleX, middleY, x3, y3) <= radius)
                        count++;
                }
                maxCount = std::max(maxCount, count);
            } else {
                double height = sqrt(radius * radius - (distanceBetween / 2) * (distanceBetween / 2));
                double normalX, normalY;
                std::tie(normalX, normalY) = getNormalVector(x1, y1, x2, y2);

                double firstCircleX = middleX + normalX * height;
                double firstCircleY = middleY + normalY * height;
                int firstCount = 0;
                for (int k = 0; k < n; k++) {
                    double x3, y3;
                    std::tie(x3, y3) = coordinates[k];
                    if (calculateDistance(firstCircleX, firstCircleY, x3, y3) <= radius)
                        firstCount++;
                }

                double secondCircleX = middleX - normalX * height;
                double secondCircleY = middleY - normalY * height;
                int secondCount = 0;
                for (int k = 0; k < n; k++) {
                    double x3, y3;
                    std::tie(x3, y3) = coordinates[k];
                    if (calculateDistance(secondCircleX, secondCircleY, x3, y3) <= radius)
                        secondCount++;
                }

                maxCount = std::max(maxCount, std::max(firstCount, secondCount));
            }
        }
    }
    return maxCount;
}

int main() {
    int testCases;
    std::cin >> testCases;
    for (int i = 0; i < testCases; i++) {
        int numberOfMosquitoes;
        double diameterOfBowl;
        std::cin >> numberOfMosquitoes >> diameterOfBowl;

        std::vector<std::pair<double, double>> coordinates;
        for (int i = 0; i < numberOfMosquitoes; i++) {
            double x, y;
            std::cin >> x >> y;
            coordinates.push_back(std::make_pair(x, y));
        }

        std::cout << maxMosquitoes(coordinates, diameterOfBowl) << std::endl;
    }
    return 0;
}