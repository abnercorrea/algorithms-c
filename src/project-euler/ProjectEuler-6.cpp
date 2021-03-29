#include <cmath>
#include <iostream>

using namespace std;

/**
 * 1. Sum of the first n integers:
 * Sn = (1 + n) * n / 2
 * 2. Square of the sum of the first n integers:
 * (Sn)^2 = (n^4 + 2n^3 + n^2) / 4
 * 3. Sum of the squares of the first n integers
 * S(n^2) = (2n^3 + 3n^2 + n) / 6
 * This comes from Telescoping Series and Telescoping Sum:
 * https://en.wikipedia.org/wiki/Telescoping_series
 * Using Ti = (i + 1)^3 - i^3, for the general series term.
 * The main idea comes from:
 * https://math.stackexchange.com/a/183320
 *
 * The value computed by this function is:
 * sumSquareDifferenceULong = (Sn)^2 - S(n^2)
 * After replacing the equations above, we land on:
 *
 * sumSquareDifferenceULong = (3n^4 + 2n^3 - 3n^2 - 2n) / 12
 *
 * Reaches unsigned long overflow at sumSquareDifference(92682)
 *
 * @param n
 * @return
 */
unsigned long sumSquareDifference(unsigned long n) {
    // This can go to the upper limit of unsigned long cause long double can accommodate larger number than unsigned long.
    // Reaches unsigned long overflow at sumSquareDifference(92682)
    return (3 * powl(n, 4) + 2 * powl(n, 3) - 3 * powl(n, 2) - 2 * n) / 12;
}

int main() {
    cout << ULONG_MAX << endl;
    cout << MAXFLOAT << endl;
    cout << "sumSquareDifference 92681: " << sumSquareDifference(92681) << " - 92682: " << sumSquareDifference(92682) << endl;

    cout << sumSquareDifference(100) << endl;

    return 0;
}
