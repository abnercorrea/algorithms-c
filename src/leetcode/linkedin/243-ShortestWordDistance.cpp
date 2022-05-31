//
// Created by Abner Correa on 4/1/22.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        if (wordsDict.empty() || word1 == word2) return 0;

        int minDistance = INT_MAX;

        for (int i = 0, w1Pos = -1, w2Pos = -1; i < wordsDict.size(); i++) {
            if (wordsDict[i] == word1 || wordsDict[i] == word2) {
                if (wordsDict[i] == word1) {
                    w1Pos = i;
                }
                else {
                    w2Pos = i;
                }

                if (w1Pos != -1 && w2Pos != -1) {
                    minDistance = min(minDistance, abs(w1Pos - w2Pos));
                }
            }
        }

        return minDistance;
    }
};
