#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// Complete the findDigits function below.
int findDigits(int n) {
    int divisors = 0;
    for (char c: to_string(n)) {
        if (c != '0' && n % short(c - '0') == 0) {
            divisors++;
        }
    }
    return divisors;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = findDigits(n);

        cout << result << "\n";
    }

    return 0;
}
