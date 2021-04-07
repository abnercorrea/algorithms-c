#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// Complete the strangeCounter function below.
long strangeCounter(long t) {
    // c = a + ar + ar^2 + ar^(n-1)
    // a = 3, r = 2
    // Sum of n first terms:
    // sum = a * (1 - r^n) / (1 - r)
    // n = log(r, 1 - (sum * (1 - r) / a))
    int a = 3, r = 2;
    long cycle = log2(1 - ((t - 1) * (1 - r) / a));
    long cycle_start = 3 * pow(2, cycle);
    long cycle_min_t = a * (1 - pow(r, cycle)) / (1 - r) + 1;
    long counter = cycle_start - (t - cycle_min_t);
    return counter;
}

int main()
{
    long t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = strangeCounter(t);

    cout << result << "\n";

    return 0;
}
