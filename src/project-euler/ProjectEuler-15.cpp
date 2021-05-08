//
// Created by Abner J Correa Jr on 5/8/21.
//
#include <algorithm>
#include <iostream>
#include <cmath>
#include "../util/timeit.h"

typedef unsigned long long ullint;

using namespace std;

/**
 * Number of NE lattice paths on a x by y lattice starting at (0,0) and ending at (x,y)
 * The number of NE (north, east) lattice paths is the binomial (n+k  n), 0 < k < n
 * (n+k  n) = (n + k)! / (n! * k!)
 *
 * https://en.wikipedia.org/wiki/Lattice_path
 *
 * @param x
 * @param y
 * @return
 */
ullint numberOfNELatticePaths(int x, int y) {
    // This is beautiful code.
    long double numPaths = 1;
    int n = max(x, y), k = min(x, y);
    // Good way to calculate (n + k)! / (n! * k!), without actually computing (n + k)! -> overflows...
    // Divides first then multiplies. This prevents overflow during the calculation.
    for (int i = 2; i <= k; i++) numPaths /= i;
    for (int i = n + 1; i <= n + k; i++) numPaths *= i;
    return round(numPaths);
}

int main() {
    // ullint overflows at d = 34
    for (int d = 1; d < 41; d++) {
        cout << d << ": " << numberOfNELatticePaths(d, d) << endl;
    }

    return 0;
}
