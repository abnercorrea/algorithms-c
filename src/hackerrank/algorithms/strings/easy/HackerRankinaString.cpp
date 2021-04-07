#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// Complete the hackerrankInString function below.
string hackerrankInString(string s) {
    string hackerrank("hackerrank");
    int hi = 0, si = 0;
    while (hi < hackerrank.length() && si < s.length()) {
        if (s.at(si) == hackerrank.at(hi)) {
            hi++;
        }
        si++;
    }
    return hi == hackerrank.length() ? "YES" : "NO";
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        string result = hackerrankInString(s);

        cout << result << "\n";
    }

    return 0;
}
