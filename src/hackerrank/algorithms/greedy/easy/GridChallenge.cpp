#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// Complete the gridChallenge function below.
string gridChallenge(vector<string> grid) {
    for (int i = 0, n = grid.size(); i < n; i++) {
        sort(grid[i].begin(), grid[i].end());
        if (i > 0) {
            for (int j = 0; j < grid[i].length(); j++) {
                if (grid[i].at(j) < grid[i - 1].at(j)) {
                    return "NO";
                }
            }
        }
    }
    return "YES";
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<string> grid(n);

        for (int i = 0; i < n; i++) {
            string grid_item;
            getline(cin, grid_item);

            grid[i] = grid_item;
        }

        string result = gridChallenge(grid);

        cout << result << "\n";
    }

    return 0;
}
