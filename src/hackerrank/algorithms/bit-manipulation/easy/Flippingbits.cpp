/*

 */
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// Complete the flippingBits function below.
long flippingBits(long n) {
    long mask = (1L << 32) - 1;
    return n ^ mask;
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        long result = flippingBits(n);

        cout << result << "\n";
    }

    return 0;
}
