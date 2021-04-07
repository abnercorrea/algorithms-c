#include <cmath>
#include <cstdio>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void maximumElement(int n, vector<vector<int>> queries) {
    stack<int> max_stack;
    max_stack.push(0);

    for (int i = 0; i < n; i++) {
        int type = queries[i][0], x;
        switch (type) {
            case 1:
                x = queries[i][1];
                max_stack.push(max(x, max_stack.top()));
                break;
            case 2: 
                if (max_stack.empty()) break;
                max_stack.pop();                                            
                break;
            case 3: 
                if (max_stack.empty()) break;
                cout << max_stack.top() << '\n';        
        } 
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> queries(n);
        
    int type, x;
    for (int i = 0; i < n; i++) {
        cin >> type;
        queries[i].push_back(type);
        if (type == 1) {
            std::cin >> x;            
            queries[i].push_back(x);
        }
    }

    /*
    cout << n << '\n';
    for (int i = 0; i < queries.size(); i++) {
        for (int j = 0; j < queries[i].size(); j++) {
            cout << queries[i][j] << ' ';  
        }
        cout << '\n';  
    }
    */

    maximumElement(n, queries);
    
    return 0;
}
