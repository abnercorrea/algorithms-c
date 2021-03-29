#include <cmath>
#include <iostream>
#include <vector>

long generatePalindrome(int p);

using namespace std;

vector<long> generatePrimeFactors(long n) {
    vector<long> factors;
    long prime = 1, sqrtN = sqrt(n);
    while (n > 1) {
        prime += (prime < 3) ? 1 : 2;
        if (prime > sqrtN) prime = n;
        if (n % prime == 0) {
            do {
                factors.push_back(prime);
                n /= prime;
            }
            while (n % prime == 0);
            sqrtN = sqrt(n);
        }
    }
    return factors;
}

long generatePalindrome(int p) {
    string left = to_string(p), right = string(left.rbegin(), left.rend());
    return stol(left + right);
}

vector<long> splitProductRecursion(long n1, long n2, long maxFactor, int i, const vector<long> &primeFactors) {
    if (n1 > maxFactor || n2 > maxFactor) return {};
    if (i < 0) return {n1, n2};

    vector<long> factors1 = splitProductRecursion(n1 * primeFactors[i], n2, maxFactor, i - 1, primeFactors);
    vector<long> factors2 = splitProductRecursion(n1, n2 * primeFactors[i], maxFactor, i - 1, primeFactors);

    return factors2.empty() ? factors1 : factors2;
}

vector<long> splitProduct(long x, int factorDigits) {
    const int maxFactor = pow(10, factorDigits);
    vector<long> primeFactors = generatePrimeFactors(x);

    return splitProductRecursion(1, 1, maxFactor, int(primeFactors.size()) - 1, primeFactors);
}

long largestPalindromeProduct(long n, int factorDigits) {
    long maxFactor = pow(10, factorDigits), minFactor = pow(10, factorDigits - 1);
    int upperBound = stoi(to_string(n - 1).substr(0, factorDigits));
    // Palindrome has to be less than n
    if (generatePalindrome(upperBound) >= n) upperBound--;
    for (int p = upperBound; p >= minFactor; p--) {
        long palindrome = generatePalindrome(p);
        vector<long> factors = splitProduct(palindrome, factorDigits);
        if (! factors.empty() && factors[0] < maxFactor && factors[0] >= minFactor && factors[1] < maxFactor && factors[1] >= minFactor) {
            cout << palindrome << " = " << factors[0] << " . " << factors[1] << '\n';
            return palindrome;
        }
    }
    return -1;
}

void printPalindromePrimeFactors(long palindrome, const vector<long>& factors) {
    cout << palindrome << " = ";
    for (long factor: factors)
        cout << factor << " ";
    cout << '\n';
}

int main() {
    // Most interesting number found in this exercise:
    // 30303030103030303
    // 30303030103030303
    // A 17 digit prime that's a palindrome!
    long interestingNumber = 30303030103030303;
    printPalindromePrimeFactors(interestingNumber, generatePrimeFactors(interestingNumber));

    //               *
    long n = 999999999;
    for (long i = 0; i < 10; i++) {
        long p = generatePalindrome(n - i);
        printPalindromePrimeFactors(p, generatePrimeFactors(p));
    }

    // cout << largestPalindromeProduct(1000000000000000000, 9) << '\n';

    return 0;
}
