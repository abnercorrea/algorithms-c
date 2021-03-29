#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Precomputed lookup table.
// entries are the primes of order 1000, 2000, 3000, ...., 10000
// This was done since the problem has the constraint n <= 10000
// Different bucket sizes can be used depending on the constraint on n.
long primesLookupTable[] = {1, 7919, 17389, 27449, 37813, 48611, 59359, 70657, 81799, 93179, 104729};

bool isPrime(unsigned long n) {
    for (long odd = 3, sqrtN = sqrt(n); true; odd += 2) {
        if (odd > sqrtN) return true;
        if (n % odd == 0) return false;
    }
}

// TODO: implement -> https://primes.utm.edu/nthprime/algorithm.php
unsigned long nthPrime(long n) {
    if (n == 1) return 2;
    int cacheIndex = min(n / 1000, 10L);
    unsigned long odd = primesLookupTable[cacheIndex];
    for (int i = (cacheIndex == 0) ? 1 : 1000 * cacheIndex; i < n; ) {
        odd += 2;
        if (isPrime(odd)) i++;
    }
    return odd;
}

int main(){
    cout << nthPrime(10001) << endl;

//    for (int i = 1; i < 11; i++)
//        cout << nthPrime(1000 * i) << endl;

    return 0;
}