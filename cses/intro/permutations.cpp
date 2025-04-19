#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;

    if (n == 1)
        cout << 1 << endl;
    else if (n == 2 || n == 3)
        cout << "NO SOLUTION" << endl;
    else {
        vector<ll> beautifulPermutation;
        
        // Even numbers first
        for (ll i = 2; i <= n; i += 2)
            beautifulPermutation.push_back(i);

        // Then odd numbers
        for (ll j = 1; j <= n; j += 2)
            beautifulPermutation.push_back(j);

        for (auto num : beautifulPermutation)
            cout << num << " ";

        cout << endl;
    }
}