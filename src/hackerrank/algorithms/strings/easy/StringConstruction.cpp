#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// Complete the stringConstruction function below.
int stringConstruction(string s) {
    int cost = 0;
    for (int i = 0; i < s.length(); i++) {
        if (!(s.find_first_of(s[i]) < i)) {
            cost++;
        }
    }
    return cost;
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = stringConstruction(s);

        cout << result << "\n";
    }

    return 0;
}
