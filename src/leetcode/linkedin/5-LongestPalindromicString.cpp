//
// Created by Abner Correa on 4/7/22.
//

#include <string>
#include <unordered_set>

using namespace std;

class Solution {
private:
    unordered_set<string> cache;

    string cacheKey(int begin, int end) {
        return to_string(begin) + "_" + to_string(end);
    }
public:
    bool isPalindromeDp(string s, int begin, int end) {
        if (begin >= end) return true;

        string key = cacheKey(begin, end);

        if (cache.find(key) != cache.end()) return true;

        bool palindrome = s[begin] == s[end] && isPalindrome(s, begin + 1, end - 1);

        if (palindrome) cache.insert(key);

        return palindrome;
    }

    bool isPalindrome(string s, int begin, int end) {
        for (int i = 0, maxI = (end - begin) / 2; i <= maxI; i++) {
            if (s[begin + i] != s[end - i]) return false;
        }

        return true;
    }

    string longestPalindrome(string s) {
        cache.clear();

        int max_start = 0, max_len = 0;

        for (int len = 1; len <= s.length(); len++) {
            for (int start = 0; start <= s.length() - len; start++) {
                if (isPalindrome(s, start, start + len - 1)) {
                    max_start = start;
                    max_len = len;
                    break;
                }
            }
        }

        return s.substr(max_start, max_len);
    }
};
