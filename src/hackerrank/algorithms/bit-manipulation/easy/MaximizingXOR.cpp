#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// Complete the maximizingXor function below.
int maximizingXor(int l, int r) {
    if (l == r) return 0;
    
    int mostSignificantXorBit = int(log2(l ^ r) + 1);
    
    return (1L << mostSignificantXorBit) - 1;
}

int main()
{
    int l;
    cin >> l;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int r;
    cin >> r;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = maximizingXor(l, r);

    cout << result << "\n";

    return 0;
}
