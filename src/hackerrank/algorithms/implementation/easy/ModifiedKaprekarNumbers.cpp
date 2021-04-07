#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// Complete the kaprekarNumbers function below.
bool isKaprekar(int n) {
    long square = pow(n, 2);
    string squareStr = to_string(square);
    int squareDigits = squareStr.length();
    int splitPos = floor(squareDigits / 2.0);
    int l = (splitPos > 0) ? stoi(squareStr.substr(0, splitPos)) : 0;
    int r = stoi(squareStr.substr(splitPos));
    return l + r == n;    
}

void kaprekarNumbers(int p, int q) {
    bool invalidRange = true;
    for (int i = p; i <= q; i++) {
        if (isKaprekar(i)) {
            cout << i << ' ';
            invalidRange = false;
        }
    }
    if (invalidRange) {
        cout << "INVALID RANGE" << '\n';
    }
}

int main()
{
    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    kaprekarNumbers(p, q);

    return 0;
}
