#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// Complete the stones function below.
vector<int> stones(int n, int a, int b) {
    if (a == b) {
        return {(n - 1) * a};
    }
    else if (b > a) {
        swap(a, b);
    }
    vector<int> lastStones(n);
    for (int i = 0; i < n; i++) {
        lastStones[i] = i * a + (n - 1 - i) * b;
    }
    return lastStones;
}

int main()
{
    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int a;
        cin >> a;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int b;
        cin >> b;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = stones(n, a, b);

        for (int i = 0; i < result.size(); i++) {
            cout << result[i];

            if (i != result.size() - 1) {
                cout << " ";
            }
        }

        cout << "\n";
    }

    return 0;
}
