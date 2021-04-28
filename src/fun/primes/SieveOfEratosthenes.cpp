#include <cmath>
#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;

/**
 * Can sieve all primes up to 10 billion (10^10) in 261sec. (2021/03/20, MacBookPro8,2)
 * Number of primes lower than or equal to 10^10: 455052511
 * Largest of prime lower than or equal to 10^10: 9999999967 (~ 10^10)
 * ULONG_MAX = 18446744073709551615
 * ceil(sqrt(ULONG_MAX)) = 4294967296 (~ 4.29e9)
 * Can sieve all primes up to 4294967296 in 103sec. (2021/03/20, MacBookPro8,2)
 * Number of primes lower than or equal to 4294967296: 203280221
 * Largest of prime lower than or equal to 4294967296: 4294967291
 *
 * @param n
 * @return
 */
vector<bool> eratosthenes(long n) {
    vector<bool> sieve(n + 1);
    long prime = 3, sqrtN = sqrt(n);
    while (prime <= sqrtN) {
        for (long multiple = prime * prime, primeDouble = prime * 2; multiple <= n; multiple += primeDouble) sieve[multiple] = true;
        prime += 2;
        while (prime < sqrtN && sieve[prime]) prime += 2;
    }
    return sieve;
}

vector<long> primesFromSieve(vector<bool> sieve) {
    if (sieve.size() < 3) return {};
    vector<long> primes{2};
    for (long i = 3; i < sieve.size(); i+=2) {
        if (!sieve[i]) primes.push_back(i);
    }
    return primes;
}

long numberOfPrimes(vector<bool> sieve) {
    if (sieve.size() < 3) return 0;
    long numPrimes = 1;
    for (long i = 3; i < sieve.size(); i+=2) if (!sieve[i]) numPrimes++;
    return numPrimes;
}

long largestPrimeLowerOrEqual(vector<bool> sieve, long n) {
    if (n >= sieve.size()) return 0;
    long prime = n % 2 == 1 ? n : n - 1;
    if (n < 3) return n;
    for (; prime > 1; prime -= 2) if (!sieve[prime]) break;
    return prime;
}

long getLargestPrime(vector<bool> sieve) {
    return largestPrimeLowerOrEqual(sieve, sieve.size() - 1);
}

void savePrimes(vector<bool> sieve) {
    ofstream f;
    f.open ("primes.txt", ios::trunc);
    f << 2 << '\n';
    for (long i = 3; i < sieve.size(); i+=2) if (!sieve[i]) f << i << '\n';
    f.close();
}

int main() {
    cout << ULONG_MAX << " - " << (long) ceill(sqrtl(ULONG_MAX)) << endl;

    //long n = ceill(sqrtl(ULONG_MAX));
    long n = 49;

    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    vector<bool> sieve = eratosthenes(n);
    chrono::steady_clock::time_point end = chrono::steady_clock::now();

    cout << "Sieve done in " << chrono::duration_cast<chrono::microseconds>(end - begin).count() << "[µs]" << endl;
    cout << "Number of primes lower than or equal to " << n << ": " << numberOfPrimes(sieve) << endl;
    cout << "Largest of prime lower than or equal to " << n << ": " << getLargestPrime(sieve) << endl;

    cout << "Saving primes to file.\n";
    //savePrimes(sieve);
    cout << "Done.\n";

    if (n < 10000) {
        vector<long> primes = primesFromSieve(sieve);
        for (long prime: primes) cout << prime << ' ';
    }

    return 0;
}