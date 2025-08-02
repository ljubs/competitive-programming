#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double vectorProduct(const pair<double, double>& origin, const pair<double, double>& a, const pair<double, double>& b) {
    double ax = a.first - origin.first;
    double ay = a.second - origin.second;
    double bx = b.first - origin.first;
    double by = b.second - origin.second;
    return ax * by - ay * bx;
}

vector<pair<double, double>> convexHull(vector<pair<double, double>> points) {
    sort(points.begin(), points.end());

    vector<pair<double, double>> hull;

    for (int phase = 0; phase < 2; phase++) {
        int start = hull.size();
        for (pair<double, double> currentPoint : points) {
            while (hull.size() >= start + 2 && 
                vectorProduct(hull[hull.size() - 2], hull[hull.size() - 1], currentPoint) <= 0)
                hull.pop_back();
            hull.push_back(currentPoint);
        }
        hull.pop_back();
        reverse(points.begin(), points.end());
    }

    return hull;
}

bool isInside(const std::vector<pair<double, double>>& hull, const pair<double, double>& point) {
    int n = hull.size();
    if (n < 3) return false;

    double firstEdgeCross = vectorProduct(hull[0], hull[1], point);
    double lastEdgeCross  = vectorProduct(hull[0], hull[n - 1], point);
    if (firstEdgeCross < 0 || lastEdgeCross > 0) return false;

    int left = 1, right = n - 2, idx = 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (vectorProduct(hull[0], hull[mid], point) >= 0) {
            idx = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return vectorProduct(hull[idx], hull[idx + 1], point) >= 0;
}

int main() {
    int l, s;

    cin >> l;
    vector<pair<double, double>> largeLanterns(l);
    for (int i = 0; i < l; i++)
        cin >> largeLanterns[i].first >> largeLanterns[i].second;

    cin >> s;
    vector<pair<double, double>> smallLanterns(s);
    for (int j = 0; j < s; j++)
        cin >> smallLanterns[j].first >> smallLanterns[j].second;

    vector<pair<double, double>> hull = convexHull(largeLanterns);

    int insideCount = 0;
    for (pair<double, double> lantern : smallLanterns)
        if (isInside(hull, lantern))
            insideCount++;

    cout << insideCount << endl;

    return 0;
}