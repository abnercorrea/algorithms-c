//
// Created by Abner Correa on 4/3/22.
//
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> openStack;
        
        for (char c: s) {
            if (c == '(' || c == '[' || c == '{') {
                openStack.push(c);    
            }
            else {
                if (openStack.empty()) return false;
                char open = openStack.top();
                if (
                    (c == ')' && open != '(') ||
                    (c == ']' && open != '[') ||
                    (c == '}' && open != '{')           
                ) {
                    return false;    
                }
                openStack.pop();    
            }
        }
        
        return openStack.empty();
    }
};

int main() {
    cout << ((string)"ABCDE").substr(2, 2) << endl;
    return 0;
}