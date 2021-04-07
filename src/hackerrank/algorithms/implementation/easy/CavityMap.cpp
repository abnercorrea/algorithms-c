#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// Complete the cavityMap function below.
vector<string> cavityMap(vector<string> grid) {
    vector<int> shape{int(grid.size()), int(grid[0].length())};
    vector<string> result(grid);
    
    for (int i = 1; i < shape[0] - 1; i++) {
        for (int j = 1; j < shape[1] - 1; j++) {
            bool isCavity = grid[i].at(j) > grid[i].at(j - 1)
                && grid[i].at(j) > grid[i].at(j + 1)
                && grid[i].at(j) > grid[i - 1].at(j)
                && grid[i].at(j) > grid[i + 1].at(j);
            if (isCavity) {
                result[i][j] = 'X';
            }
        }
    }
            
    return result;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = cavityMap(grid);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}
