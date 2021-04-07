#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

vector<string> split_string(string);

// Complete the stoneDivision function below.
long stoneDivisionDP(long n, vector<long> s, map<long, long> &cache);

long stoneDivision(long n, vector<long> s) {
    map<long, long> cache;
    
    return stoneDivisionDP(n, s, cache);
}

long stoneDivisionDP(long n, vector<long> s, map<long, long> &cache) {
    if (cache.count(n) > 0) {
        return cache[n];
    }
    vector<long> moves(s.size(), 0);
     
    for (int i = 0; i < s.size(); i++) {
        if (n != s[i] && n % s[i] == 0) {
            moves[i] = 1 + n / s[i] * stoneDivisionDP(s[i], s, cache);   
        }
    }

    long maxMoves = *max_element(std::begin(moves), std::end(moves));
    cache[n] = maxMoves;
        
    return maxMoves;
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        long n = stol(nm[0]);

        int m = stoi(nm[1]);

        string s_temp_temp;
        getline(cin, s_temp_temp);

        vector<string> s_temp = split_string(s_temp_temp);

        vector<long> s(m);

        for (int i = 0; i < m; i++) {
            long s_item = stol(s_temp[i]);

            s[i] = s_item;
        }

        long result = stoneDivision(n, s);

        cout << result << "\n";
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
