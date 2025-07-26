#include <iostream>
using namespace std;

int main() {
    string name, result;
    cin >> name;
    result += name.at(0);
    for (int i = 1; i < name.length() - 1; i++)
        if (name.at(i) == '-')
            result += name.at(i + 1);
    cout << result << endl;
    return 0;
}