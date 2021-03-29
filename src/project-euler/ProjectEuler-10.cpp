#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include "../util/timeit.h"

using namespace std;

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

map<long, long> sumOfPrimes(vector<long> n) {
    sort(n.begin(), n.end());
    vector<bool> sieve = eratosthenes(n.back());
    map<long, long> sums;
    long sum = 2, ni = 0;
    for (; ni < n.size() && n[ni] < 2; ni++) sums[n[ni]] = n[ni];
    for (long prime = 3; ni < n.size() && prime < sieve.size(); prime+=2) {
        if (!sieve[prime]) {
            for (; prime > n[ni]; ni++) sums[n[ni]] = sum;
            sum += prime;
        }
    }
    for (; ni < n.size(); ni++) sums[n[ni]] = sum;
    return sums;
}

int main(){
//    int t;
//    cin >> t;
//    vector<long> ns(t);
//    for(int a0 = 0; a0 < t; a0++) cin >> ns[a0];
    vector<long> ns{0, 1, 2, 3, 7, 10, 11, 100, 101, 102, 1000, 10000, 100000, 1000000};

    cout << "Time taken: " << timeIt(sumOfPrimes, ns) << "ms" << endl;

    map<long, long> sums = sumOfPrimes(ns);
    for(long n: ns) cout << sums[n] << endl;

    return 0;
}
