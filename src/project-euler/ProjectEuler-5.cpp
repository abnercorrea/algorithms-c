/**
 * What is the smallest positive number that is evenly divisible(divisible with no remainder) by all of the numbers from 1 to N?
 */

#include <cmath>
#include <iostream>
#include <map>
#include <vector>

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

long smallestMultiple(long n) {
    map<int, int> primeFactors;
    long m = 1;
    for (int divisor = n; divisor > 1; divisor--) {
        if (m % divisor != 0) {
            map<int, int> divisorFactors = generatePrimeFactors(divisor);

            for (map<int, int>::iterator itr = divisorFactors.begin(); itr != divisorFactors.end(); ++itr) {
                if (itr->second > primeFactors[itr->first]) {
                    m *= pow(itr->first, itr->second - primeFactors[itr->first]);
                    primeFactors[itr->first] = itr->second;
                }
            }
        }
    }
    return m;
}

int main() {
    cout << smallestMultiple(20);

    return 0;
}
