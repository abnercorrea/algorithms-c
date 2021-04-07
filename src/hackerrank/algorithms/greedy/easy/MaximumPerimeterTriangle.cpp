#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

vector<string> split_string(string);

// Complete the maximumPerimeterTriangle function below.
vector<int> maximumPerimeterTriangle(vector<int> sticks) {
    sort(sticks.begin(), sticks.end());
            
    for (int n = sticks.size(), i = n - 3; i >= 0; i--) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                bool formTriangle = sticks[i] + sticks[j] > sticks[k];
                if (formTriangle) {
                    return {sticks[i], sticks[j], sticks[k]};   
                }
                else {
                    break;
                }
            }
        }
    }

    return {-1};
}


vector<int> maximumPerimeterTriangleNotGreedy(vector<int> sticks) {
    int i = 0, n = sticks.size(), maxPerimiter = 0;
    vector<int> mpt{-1};
    
    sort(sticks.begin(), sticks.end());
        
    while (i < n - 2 and sticks[i] == 0) i++;
    
    for (; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                bool formTriangle = sticks[i] + sticks[j] > sticks[k];
                if (formTriangle) {
                    int p = sticks[i] + sticks[j] + sticks[k];
                    if (p > maxPerimiter) {
                        maxPerimiter = p;
                        mpt = {sticks[i], sticks[j], sticks[k]};   
                    }
                    else if (p == maxPerimiter) {
                        int newLongestSide = sticks[k], oldLongestSide = mpt[2];
                        if (newLongestSide > oldLongestSide) {
                            mpt = {sticks[i], sticks[j], sticks[k]};
                        }
                        else if (newLongestSide == oldLongestSide) {
                            int newShortestSide = sticks[i], oldShortestSide = mpt[0];
                            if (newShortestSide > oldShortestSide) {
                                mpt = {sticks[i], sticks[j], sticks[k]};
                            }
                        }
                    }
                }
                else {
                    break;
                }
            }
        }
    }

    return mpt;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string sticks_temp_temp;
    getline(cin, sticks_temp_temp);

    vector<string> sticks_temp = split_string(sticks_temp_temp);

    vector<int> sticks(n);

    for (int i = 0; i < n; i++) {
        int sticks_item = stoi(sticks_temp[i]);

        sticks[i] = sticks_item;
    }

    vector<int> result = maximumPerimeterTriangle(sticks);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << " ";
        }
    }

    cout << "\n";

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
