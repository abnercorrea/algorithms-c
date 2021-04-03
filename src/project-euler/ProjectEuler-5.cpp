/**
 * What is the smallest positive number that is evenly divisible(divisible with no remainder) by all of the numbers from 1 to N?
 */

#include <cmath>
#include <iostream>
#include <map>

using namespace std;

/**
 * key = prime, value = exponent
 * @param n
 * @return
 */
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

            for (auto & divisorFactor: divisorFactors) {
                if (divisorFactor.second > primeFactors[divisorFactor.first]) {
                    m *= pow(divisorFactor.first, divisorFactor.second - primeFactors[divisorFactor.first]);
                    primeFactors[divisorFactor.first] = divisorFactor.second;
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
