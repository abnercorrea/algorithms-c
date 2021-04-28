#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// Found it!
static unsigned long largestPrime = 18446744073709551557UL;

// The largest long primesLookupTable.
vector<unsigned long> largestPrimes {
    18446744073709551557UL,
    18446744073709551533UL,
    18446744073709551521UL,
    18446744073709551437UL,
    18446744073709551427UL,
    18446744073709551359UL,
    18446744073709551337UL,
    18446744073709551293UL,
    18446744073709551263UL,
    18446744073709551253UL,
    18446744073709551191UL,
    18446744073709551163UL,
    18446744073709551113UL,
    18446744073709550873UL,
    18446744073709550791UL,
    18446744073709550773UL,
    18446744073709550771UL,
    18446744073709550719UL,
    18446744073709550717UL,
    18446744073709550681UL,
    18446744073709550671UL,
    18446744073709550593UL,
    18446744073709550591UL,
    18446744073709550539UL,
    18446744073709550537UL,
};

/**
 * https://mathworld.wolfram.com/GreatestPrimeFactor.html
 * - A number N for which its largest prime factor is > sqrt(N) is called:
 * - an unusual number by Greene and Knuth (1990)
 * - Or sqrt(n)-rough numbers by Finch (2001)
 * - Or a "jagged" number. (https://oeis.org/A064052)
 */
bool isPrime(unsigned long n) {
    if (n == 2) return true;
    if (n % 2 == 0 || n == 1) return false;
    for (long odd = 3, sqrtN = sqrt(n); odd <= sqrtN; odd += 2) {
        if (n % odd == 0) return false;
    }
    return true;
}

int main(){
    cout << "Largest Long : " << ULONG_MAX << endl;
    cout << "Largest prime: " << largestPrime << endl;
    double largestPrimeLog2 = log2l(largestPrime);
    cout << "Largest prime log2: " << largestPrimeLog2 << endl;
    cout << "2^64 - 1: " << (unsigned long) (powl(2, 64) - 1) << endl;

    // ULONG_MAX = 18446744073709551615, is an odd number.
//    for (unsigned long l = ULONG_MAX; true; l -= 2) {
//        if (isPrime(l)) {
//            cout << l << endl;
//            break;
//        }
//    }

    return 0;
}