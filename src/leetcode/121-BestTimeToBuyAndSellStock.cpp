//
// Created by Abner J Correa Jr on 4/16/21.
//
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

typedef vector<int> InputType;

static vector<InputType> testCases = {
        {7, 1, 5, 3, 6, 4},
};

// 2,3,1,5,7,1,6
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        for (int i = 0, min = INT_MAX; i < prices.size(); i++) {
            if (prices[i] < min) {
                min = prices[i];
            } else if (prices[i] - min > profit) {
                profit = prices[i] - min;
            }
        }
        return profit;
    }
};

int main() {
    Solution *solution = new Solution();

    for (InputType testCase: testCases) {
        cout << solution->maxProfit(testCase) << endl;
    }

    return 0;
}
