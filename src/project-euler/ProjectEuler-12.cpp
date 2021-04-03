#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include "../util/timeit.h"

using namespace std;

map<int, int> generatePrimeFactors(long n) {
    map<int, int> factors;
    long prime = 1, sqrtN = sqrt(n);
    while (n > 1) {
        prime += (prime < 3) ? 1 : 2;
        if (prime > sqrtN) prime = n;
        if (n % prime == 0) {
            int exp = 0;
            do {
                exp++;
                n /= prime;
            }
            while (n % prime == 0);
            factors[prime] = exp;
            sqrtN = sqrt(n);
        }
    }
    return factors;
}

int numberOfDivisors(long n) {
    // key = prime, value = exponent
    map<int, int> primeFactors = generatePrimeFactors(n);
    int divisors = 1;
    for (auto & primeFactor : primeFactors) {
        divisors *= primeFactor.second + 1;
    }
    return divisors;
}

int numberOfDivisorsDP(long n, map<long, int> &cache) {
    if (cache.count(n) == 1) return cache[n];
    int divisors = numberOfDivisors(n);
    cache[n] = divisors;
    return divisors;
}

/**
 * Since triangular = n * (n + 1) / 2...
 */
long triangularNumberDivisors(long n) {
    if (n % 2 == 0)
        return numberOfDivisors(n / 2) * numberOfDivisors(n + 1);
    else
        return numberOfDivisors(n) * numberOfDivisors((n + 1) / 2);
}

/**
 * 1,1 1,3 3,2 2,5 5,3 3,7 7,4 4,9 9,5 5,11
 */
long triangularNumberDivisorsDP(long n, map<long, int> &cache) {
    if (n % 2 == 0)
        return numberOfDivisorsDP(n / 2, cache) * numberOfDivisorsDP(n + 1, cache);
    else
        return numberOfDivisorsDP(n, cache) * numberOfDivisorsDP((n + 1) / 2, cache);
}

long highlyDivisibleTriangularNumber(int minDivisors) {
    for (int i = 1; true; i++) {
        long numDivisors = triangularNumberDivisors(i);
        if (numDivisors > minDivisors) {
            return (long(i) * (i + 1)) / 2L;
        }
    }
}

long highlyDivisibleTriangularNumberDP(int minDivisors) {
    map<long, int> cache;
    for (int i = 1; true; i++) {
        long numDivisors = triangularNumberDivisorsDP(i, cache);
        if (numDivisors > minDivisors) {
            return (long(i) * (i + 1)) / 2L;
        }
    }
}

long highlyDivisibleTriangularNumberDebug(int minDivisors) {
    long maxDivisors = 0;
    for (int i = 1; true; i++) {
        long numDivisors = triangularNumberDivisors(i);
        maxDivisors = max(numDivisors, maxDivisors);
        cout << i << ", " << maxDivisors << "                                      " << '\r' << flush;
        if (numDivisors > minDivisors) {
            cout << endl;
            return (long(i) * (i + 1)) / 2L;
        }
    }
}

long highlyDivisibleTriangularNumberSlow(int minDivisors) {
    for (int i = 1; true; i++) {
        long t = (long(i) * (i + 1)) / 2L;
        if (numberOfDivisors(t) > minDivisors) return t;
    }
}

int main() {
    // n^2 + n - 2LONG_MAX = 0
    // n = (-1 + sqrt(1 + 8LONG_MAX)) / 2
    long maxN = (-1 + (2 * sqrt(2) * sqrt(LONG_MAX))) / 2;

    cout << "Max N: " << maxN << endl;

    long n = 15000;
    cout << "Time taken DP: " << timeIt(highlyDivisibleTriangularNumberDP, n) << "ms" << endl;
    cout << "Time taken: " << timeIt(highlyDivisibleTriangularNumber, n) << "ms" << endl;

    // cout << highlyDivisibleTriangularNumber(1000) << endl;
    // cout << highlyDivisibleTriangularNumberDebug(10000) << endl;

    return 0;
}