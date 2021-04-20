//
// Created by Abner J Correa Jr on 4/20/21.
//
class Solution {
public:
    int tribonacci(int n) {
        if (n < 2)
            return n;
        else if (n == 2)
            return 1;

        int x = 0, y = 1, z = 1, t;

        for (int i = 3; i <= n; i++) {
            t = x + y + z;
            x = y;
            y = z;
            z = t;
        }

        return t;
    }
};
