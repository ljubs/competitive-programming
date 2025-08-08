#include <iostream>
#include <vector>

bool canColor(std::vector<std::vector<int>> graph, int vertex, int color, std::vector<int> colors) {
    for (auto neighbour : graph[vertex])
        if (colors[neighbour] == color)
            return false;
    return true;
}

bool colorGraph(int maxColors, std::vector<std::vector<int>> graph) {
    std::vector<int> attemptedColors(graph.size(), 0);
    std::vector<int> assignedColors(graph.size(), 0);

    int vertex = 0;
    while (vertex >= 0 && vertex < graph.size()) {
        attemptedColors[vertex]++;
        
        if (attemptedColors[vertex] > maxColors) {
            attemptedColors[vertex] = 0;
            assignedColors[vertex] = 0;
            vertex--;
            continue;
        }
        
        if (canColor(graph, vertex, attemptedColors[vertex], assignedColors)) {
            assignedColors[vertex] = attemptedColors[vertex];
            vertex++;
            if (vertex == graph.size()) {
                for (auto color : assignedColors)
                    std::cout << color;
                std::cout << std::endl;
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    int testCases;
    std::cin >> testCases;
    for (int i = 0; i < testCases; i++) {
        int numberOfCountries, numberOfBorders;
        std::cin >> numberOfCountries >> numberOfBorders;

        if (numberOfBorders == 0) {
            std::cout << 1 << std::endl;
            continue;
        }

        std::vector<std::vector<int>> graph(numberOfCountries);
        for (int i = 0; i < numberOfBorders; i++) {
            int u, v;
            std::cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        for (int i = 1; i <= 4; i++) {
            if (colorGraph(i, graph)) {
                std::cout << i << std::endl;
                break;
            }

            if (i == 4)
                std::cout << "many" << std::endl;
        }
    }

    return 0;
}