//
// Created by Abner J Correa Jr on 4/20/21.
//
class Solution {
private:
    static int intAsc(const void * a, const void * b) {
      return ( *(int*)a - *(int*)b );
    }

public:
    vector<int> numMovesStones(int a, int b, int c) {
        int x[] = {a, b, c};
        qsort(x, 3, sizeof(int), intAsc);
        int d1 = x[1] - x[0] - 1, d2 = x[2] - x[1] - 1;
        int min = (d1 == 0 && d2 == 0) ? 0 : (d1 < 2 || d2 < 2) ? 1 : 2;
        int max = d1 + d2;
        return {min , max};
    }
};
