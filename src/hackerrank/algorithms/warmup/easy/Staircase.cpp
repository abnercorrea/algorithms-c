#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// Complete the staircase function below.
void staircase(int n) {
    for (int i = 1; i <= n; i++) {
        cout << string(n - i, ' ') << string(i, '#') << '\n'; 
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    staircase(n);

    return 0;
}
