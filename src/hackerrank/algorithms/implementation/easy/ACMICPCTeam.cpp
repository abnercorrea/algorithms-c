#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

vector<string> split_string(string);

// Complete the acmTeam function below.
int countOnes(string n1, string n2) {
    int ones = 0;
    for (int i = 0; i < n1.length(); i++) {
        if ((n1.at(i) | n2.at(i)) == '1') ones++;
    }
    return ones;
}

int countOnesOr(string n1, string n2) {
    int ones = 0;
    for (int block = 0, total_blocks = ceil(n1.length() / 64.0); block < total_blocks; block++) {
        long long b1 = stoll(n1.substr(64 * block, 64), nullptr, 2);
        long long b2 = stoll(n2.substr(64 * block, 64), nullptr, 2);
        long long n = b1 | b2, one_mask = 1;
        for (int i = 0; n >= one_mask; one_mask = 1 << ++i) {
            if ((n & one_mask) != 0) ones++;
        }
    }
    return ones;
}

vector<int> acmTeam(vector<string> topic) {
    int maxTopics = 0, bestTeams = 0;
    for (int i = 0, n = topic.size(); i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int knownTopics = countOnes(topic[i], topic[j]);
            if (knownTopics == maxTopics) {
                bestTeams++;
            }
            else if (knownTopics > maxTopics) {
                maxTopics = knownTopics;
                bestTeams = 1;
            }
        }
    }
    return {maxTopics, bestTeams};
}

int main()
{
    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<string> topic(n);

    for (int i = 0; i < n; i++) {
        string topic_item;
        getline(cin, topic_item);

        topic[i] = topic_item;
    }

    vector<int> result = acmTeam(topic);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
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
