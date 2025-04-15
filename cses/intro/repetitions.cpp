#include <iostream>
using namespace std;

int main() {
    string characters;
    cin >> characters;

    int currentRepetition = 1;
    int longestRepetition = 1;

    for (int i = 1; i < characters.length(); i++) {
        if (characters[i - 1] == characters[i])
            currentRepetition++;
        else {
            longestRepetition = max(longestRepetition, currentRepetition);
            currentRepetition = 1;
        }
    }

    longestRepetition = max(longestRepetition, currentRepetition); // Check final repetition after the loop
    cout << longestRepetition << endl;
    return 0;
}