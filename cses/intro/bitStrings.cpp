#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
    ll exponent;
    cin >> exponent;

    ll mod = pow(10, 9) + 7;
    ll result = 1;
    for (int i = 1; i <= exponent; i++)
        result = (2 * result) % mod;
    cout << result << endl;
    return 0;
}