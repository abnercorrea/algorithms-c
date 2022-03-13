//
// Created by Abner Correa on 3/13/22.
//

#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int powerSumRec(int x, vector<int> powers, int sum, int i) {
    if (i == powers.size()) return 0;

    int combinations = 0;

    for (int j = i, maxJ = powers.size(); j < maxJ; j++) {
        int newSum = sum + powers[j];
        if (newSum == x) {
            combinations++;
        }
        else if (newSum < x) {
            combinations += powerSumRec(x, powers, newSum, j + 1);
        }
    }

    return combinations;
}

int powerSum(int x, int n) {
    int max = pow(x, 1. / n);

    vector<int> powers(max);
    for (int i = 0; i < max; i++) {
        powers[i] = pow(i + 1, n);
    }

    return powerSumRec(x, powers, 0, 0);
}

int main() {
    cout << powerSum(10, 2) << "\n";
    cout << powerSum(100, 2) << "\n";
    cout << powerSum(100, 3) << "\n";
    cout << powerSum(160000, 4) << "\n";

    return 0;
}
