//
// Created by Abner J Correa Jr on 4/16/21.
//
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1; else if (n == 3) return 2;

        int threes = n / 3, r = n % 3, twos = 0;

        switch (r) {
            case 1:
                threes--;
                twos = 2;
                break;
            case 2:
                twos = 1;
        }

        return pow(3, threes) * pow(2, twos);
    }
};
