#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> result = {n};

     while (n != 1) {
        if (n % 2 == 0)
            n /= 2;
        else
            n = n * 3 + 1;
        result.push_back(n);
    }

    for (int num : result)
        cout << num << " ";
    cout << "\n";

    return 0;
}