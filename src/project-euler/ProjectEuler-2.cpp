#include <iostream>

using namespace std;

long evenFibonacciSum(long n) {
    if (n < 2) return 0;
    long sum = 2;
    long fibN = 8, fibNMinusOne = 2, fibNMinusTwo = 0;
    while (fibN <= n) {
        sum += fibN;
        fibNMinusTwo = fibNMinusOne;
        fibNMinusOne = fibN;
        fibN = 4 * fibNMinusOne + fibNMinusTwo;
    }
    return sum;
}

long evenFibonacciSumBruteForce(long n) {
    long sum = 0;
    long fibN = 1, fibNMinusOne = 1, fibNMinusTwo = 0;
    while (fibN <= n) {
        if (fibN % 2 == 0) sum += fibN;
        fibNMinusTwo = fibNMinusOne;
        fibNMinusOne = fibN;
        fibN = fibNMinusOne + fibNMinusTwo;
    }
    return sum;
}

int main(){
    cout << evenFibonacciSum(4000000) << '\n';

    return 0;
}