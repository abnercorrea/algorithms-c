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

// Complete the makingAnagrams function below.
int makingAnagrams(string s1, string s2) {
    vector<int> lf1 = letter_frequency(s1);
    vector<int> lf2 = letter_frequency(s2);
    int deletions = 0;
    for (int i = 0; i < lf1.size(); i++) {
        deletions += abs(lf1[i] - lf2[i]);
    }
    return deletions;
}

int main()
{
    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = makingAnagrams(s1, s2);

    cout << result << "\n";

    return 0;
}
