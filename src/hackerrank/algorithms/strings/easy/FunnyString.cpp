#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// Complete the funnyString function below.
string funnyString(string s) {
    for (int i = 1, n = s.length(); i < n; i++) {
        if (abs(s.at(i) - s.at(i - 1)) != abs(s.at(n - i) - s.at(n + -i -1))) {
            return "Not Funny";
        }
    }
    return "Funny";
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        string result = funnyString(s);

        cout << result << "\n";
    }

    return 0;
}
