//
// Created by Abner J Correa Jr on 4/23/21.
//
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

typedef vector<vector<int>> InputType;

static vector<InputType> testCases = {
        {
                {1, 2, 2, 1},
                {3, 1, 2},
                {1, 3, 2},
                {2, 4},
                {3, 1, 2},
                {1, 3, 1, 1},
        },
        {
                {100000000}
        },
        {{1,1},{2},{1,1}}
};

// sum       i       cuts    minSum    minCuts
// 1,2,1     1,1,1   0       1         3
// 2,2,2     2,1,2   1       2         1

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int nrows = wall.size(), minCuts = nrows, minSum = 0;
        vector<int> sum(nrows), i(nrows);
        bool edge;

        do {
            edge = true;
            int cuts = 0;

            for (int row = 0; row < nrows; row++) {
                if (sum[row] == minSum) {
                    sum[row] += wall[row][i[row]];
                    i[row]++;
                }
                else cuts++;

                edge &= i[row] == wall[row].size();
            }

            if (cuts < minCuts && minSum > 0) minCuts = cuts;
            minSum = *min_element(sum.begin(), sum.end());
        }
        while (!edge);

        return minCuts;
    }
};

int main() {
    Solution *solution = new Solution();

    for (InputType testCase: testCases) {
        cout << solution->leastBricks(testCase) << endl;
    }

    return 0;
}
