#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

long sumOfMultiples(long n, long x, long y) {
    long maxN = n - 1, nx = maxN / x, ny = maxN / y, xy = x * y, nxy = maxN / xy;
    long sumX = (x * nx * (1 + nx)) / 2;
    long sumY = (y * ny * (1 + ny)) / 2;
    long sumXY = (xy * nxy * (1 + nxy)) / 2;
    return sumX + sumY - sumXY;
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        cout << sumOfMultiples(n, 3, 5) << '\n';
    }
    return 0;
}