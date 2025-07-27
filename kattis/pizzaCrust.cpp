#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int R, C;
    cin >> R >> C;
    double cheesyArea = M_PI * pow(R - C, 2.0);
    double totalArea = M_PI * pow(R, 2.0);
    double percentage = cheesyArea / totalArea * 100;
    cout << fixed << setprecision(6) << percentage << endl;
    return 0;
}