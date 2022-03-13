//
// Created by Abner Correa on 3/7/22.
//
#include <iostream>
#include <gmp.h>

using namespace std;

char *extraLageFactorial(int n) {
    mpz_t factorial;
    mpz_init(factorial);
    mpz_set_ui(factorial, 1);

    for (int i = 1; i <= n; i++) {
        mpz_mul_ui(factorial, factorial, i);
    }

    char *factorialStr = mpz_get_str(NULL, 10, factorial);  // base 10

    return factorialStr;
}

int main() {
    cout << extraLageFactorial(4) << "\n";
    cout << extraLageFactorial(20) << "\n";
    cout << extraLageFactorial(40) << "\n";
    cout << extraLageFactorial(100) << "\n";
}