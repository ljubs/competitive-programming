#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;

    ll expectedSum = (n * (n + 1)) / 2; // Sum of numbers from 1 to n (triangular number)
    ll actualSum = 0;
    ll num;

    for (int i = 0; i < n - 1; i++) {
        cin >> num;
        actualSum += num;
    }

    ll missingNumber = expectedSum - actualSum;
    cout << missingNumber << endl;
    return 0;
}