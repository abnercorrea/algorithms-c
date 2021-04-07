#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the sumXor function below.
long sumXor(long n) {
    // 10100
    // 0x0xx, x -> 0, 1
    long count = 1;
    for (int i = 0, num_bits = int(log2(n) + 1); i < num_bits; i++) {
        if ((n & 1L << i) == 0) {
            count *= 2;
        }    
    }
    return count;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    long result = sumXor(n);

    cout << result << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
