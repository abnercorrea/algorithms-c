#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// Complete the gameOfThrones function below.
string gameOfThrones(string s) {
    short a = int('a'), n = int('z') - a + 1;
    vector<int> letter_freq(n);
    for (int i = 0;  i < s.length(); i++) {
        letter_freq[s.at(i) - a]++;
    }
    short odd_count = 0;
    for (int i = 0; i < n; i++) {
        if (letter_freq[i] % 2 == 1) {
            odd_count++;
        }
    }
    return odd_count < 2 ? "YES" : "NO";
}

int main()
{
    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    cout << result << "\n";

    return 0;
}
