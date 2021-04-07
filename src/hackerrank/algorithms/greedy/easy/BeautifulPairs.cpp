#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

vector<string> split_string(string);

// Complete the beautifulPairs function below.
vector<int> countNumbers(vector<int> A, int maxNum) {
    vector<int> freq(maxNum + 1);
    for (int i = 0, n = A.size(); i < n; i ++)
        freq[A[i]]++;
    return freq;
}

int beautifulPairs(vector<int> A, vector<int> B) {
    int maxNum = 1000, count = 0;
    vector<int> freqA = countNumbers(A, maxNum), freqB = countNumbers(B, maxNum);
    bool replacedB = false;
    for (int i = 1; i <= maxNum; i++) {
        if (freqA[i] > 0 || freqB[i] > 0) {
            count += min(freqA[i], freqB[i]);
            if (freqB[i] != freqA[i] && ! replacedB) {
                replacedB = true;
                count++;                
            }    
        }
    }
    if (!replacedB) count--;
    return count;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string A_temp_temp;
    getline(cin, A_temp_temp);

    vector<string> A_temp = split_string(A_temp_temp);

    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        int A_item = stoi(A_temp[i]);

        A[i] = A_item;
    }

    string B_temp_temp;
    getline(cin, B_temp_temp);

    vector<string> B_temp = split_string(B_temp_temp);

    vector<int> B(n);

    for (int i = 0; i < n; i++) {
        int B_item = stoi(B_temp[i]);

        B[i] = B_item;
    }

    int result = beautifulPairs(A, B);

    cout << result << "\n";

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
