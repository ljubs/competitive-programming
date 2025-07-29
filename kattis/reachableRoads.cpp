#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

int main() {
    int testCases, numberOfCities, numberOfWorkingRoads;
    cin >> testCases;
    for (int i = 0; i < testCases; i++) {
        cin >> numberOfCities;
        cin >> numberOfWorkingRoads;
        vector<vector<int>> neighbors(numberOfCities);
        for (int j = 0; j < numberOfWorkingRoads; j++) {
            int a, b;
            cin >> a >> b;
            neighbors.at(a).push_back(b);
            neighbors.at(b).push_back(a);        
        }

        unordered_set<int> visited;
        queue<int> queue;
        int components = 0;
        for (int k = 0; k < numberOfCities; k++) {
            if (visited.find(k) != visited.end()) {
                continue;
            }
            int start = k;
            queue.push(start);
            visited.insert(start);
            components++;
            while (!queue.empty()) {
                int current = queue.front();
                queue.pop();

                for (auto neighbor : neighbors[current]) {
                    if (visited.find(neighbor) == visited.end()) {
                        queue.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
            }
        }

        int roadsToBuild = components - 1;
        cout << roadsToBuild << endl;
    }
    return 0;
}