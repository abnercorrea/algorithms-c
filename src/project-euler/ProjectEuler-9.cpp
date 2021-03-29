#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

long specialPythagorianTriplet(long n) {
    long maxProduct = -1;
    for (long c = ceill(n / 2) - 1; true; c--) {
        long delta = powl(c, 2) + 2 * n * c - powl(n, 2);
        if (delta < 0) {
            cout << "c = " << c << " delta = " << delta << endl;
            break;
        }
        long double sqrtDelta = sqrtl(delta);
        if (sqrtDelta != (long) sqrtDelta) continue;
        long a = (n - c - sqrtDelta) / 2;
        long b = (n - c + sqrtDelta) / 2;
        cout << "(a, b, c) = (" << a << ", " << b << ", " << c << ") abc = " << a * b * c << " delta = " << delta << endl;
        maxProduct = max(a * b * c, maxProduct);
    }
    return maxProduct;
}

int main() {
    cout << specialPythagorianTriplet(1000) << endl;

    return 0;
}