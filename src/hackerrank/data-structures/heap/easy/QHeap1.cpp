#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

vector<string> split_string(string);

vector<int> qheap(vector<vector<int>> queries) {
    vector<int> result;
    priority_queue <int, vector<int>, greater<int>> heap;
    stack<int> temp;

    for (int i = 0; i < queries.size(); i++) {
        switch (queries[i][0]) {
            case 1:
                heap.push(queries[i][1]);
                break;
            case 2:
                cout << "Deleting " << queries[i][1] << " Heap top " << heap.top() << '\n';
                while (heap.top() != queries[i][1]) {
                    temp.push(heap.top());
                    heap.pop();
                }
                heap.pop();
                while (!temp.empty()) {
                    heap.push(temp.top());
                    temp.pop();
                }
                break;
            case 3:
                result.push_back(heap.top());
        }
    }
    return result;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> contests(n);
    for (int i = 0; i < n; i++) {
        contests[i].resize(2);

        cin >> contests[i][0];
        if (contests[i][0] < 3) cin >> contests[i][1];

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> results = qheap(contests);

    for (int n: results) {
        cout << n << '\n';
    }

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
