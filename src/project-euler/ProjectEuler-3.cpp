#include <cmath>
#include <iostream>

using namespace std;

/**
 * https://mathworld.wolfram.com/GreatestPrimeFactor.html
 * - A number N for which its largest prime factor is > sqrt(N) is called:
 * - an unusual number by Greene and Knuth (1990)
 * - Or sqrt(n)-rough numbers by Finch (2001)
 * - Or a "jagged" number. (https://oeis.org/A064052)
 */
long largestPrimeFactor(long n) {
    if (n < 2) return 1;
    while (n % 2 == 0) n /= 2;
    if (n == 1) return 2;
    long prime = 1, sqrtN = sqrt(n);
    while (n > 1) {
        prime += 2;
        if (prime > sqrtN) prime = n;
        if (n % prime == 0) {
             do {
                n /= prime;
            }
           while (n % prime == 0);

            sqrtN = sqrt(n);
        }
    }
    return prime;
}

int main(){
    cout << largestPrimeFactor(LONG_MAX) << '\n';

    return 0;
}