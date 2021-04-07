#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// Complete the palindromeIndex function below.
int palindromeIndex(string s) {
    int diffIndex = -1, backtrackL = -1, backtrackR = -1;
    for (int l = 0, r = s.length() - 1, mid = s.length() / 2; l < r;) {
        if (s[l] == s[r]) {
            l++;
            r--;
        }
        else if (diffIndex == -1) {
            backtrackL = l;
            backtrackR = r;
            diffIndex = l++;
        }
        else if (diffIndex < mid) {
            l = backtrackL;
            r = backtrackR - 1;
            diffIndex = backtrackR;
        } 
        else {
            return -1;
        }
    }
    return diffIndex;
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = palindromeIndex(s);

        cout << result << "\n";
    }

    return 0;
}
