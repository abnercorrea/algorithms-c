//
// Created by Abner Correa on 4/8/22.
//
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, len = s.length();
        if (s.empty()) return 0;
        while (s[i] == ' ') i++;
        if (i == len) return 0;
        int sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '-' || s[i] == '+') i++;
        long x = 0, maxInt = 1L << 31;
        for (; i < len && s[i] >= '0' && s[i] <= '9' && x < maxInt; i++) {
            x = (x * 10) + (s[i] - '0');
        }
        x *= sign;
        x = min(max(x, -maxInt), maxInt - 1);
        return x;
    }
};
