#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// Complete the camelcase function below.
int camelcase(string s) {
    int upper_count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            upper_count++;
        } 
    }
    return s.empty() ? 0 : upper_count + 1;
}

int main()
{
    string s;
    getline(cin, s);

    int result = camelcase(s);

    cout << result << "\n";

    return 0;
}
