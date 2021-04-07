#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> letter_frequency(string s) {
    short a = short('a'), n = short('z') - a + 1;
    vector<int> lf(n);
    for (int i = 0; i < s.length(); i++) {
        lf[s.at(i) - a]++;
    }
    return lf;
}

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {
    vector<int> lf1 = letter_frequency(s1);
    vector<int> lf2 = letter_frequency(s2);
    for (int i = 0; i < lf1.size(); i++) {
        if (lf1[i] > 0 && lf2[i] > 0) {
            return "YES";
        }
    }
    return "NO";
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        cout << result << "\n";
    }

    return 0;
}
