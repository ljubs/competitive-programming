#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;

    vector<ll> result = {n};

     while (n != 1) {
        if (n % 2 == 0)
            n /= 2;
        else
            n = n * 3 + 1;
        result.push_back(n);
    }

    for (ll num : result)
        cout << num << " ";
    cout << "\n";

    return 0;
}