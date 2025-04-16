#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;

    vector<ll> nums;
    ll num;
    for (ll i = 0; i < n; i++) {
        cin >> num;
        nums.push_back(num);
    }

    ll moves = 0;
    for (ll i = 1; i < n; i++) {
        if (nums[i - 1] > nums[i]) {
            moves += nums[i - 1] - nums[i];
            nums[i] = nums[i - 1];
        }
    }

    cout << moves << endl;
    return 0;
}