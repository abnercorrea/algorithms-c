#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// Complete the anagram function below.
int anagram(string s) {
    if (s.length() % 2 == 1) return -1;
    
    vector<int> left(26), right(26);
    int mid = s.length() / 2;
    for (int i = 0; i < mid; i++) {
        left[s[i] - 'a']++;
        right[s[i + mid] - 'a']++;
    }
    int equal = 0;
    for (int i = 0; i < left.size(); i++) {
        equal += min(left[i], right[i]);
    }
    return mid - equal;
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = anagram(s);

        cout << result << "\n";
    }

    return 0;
}
