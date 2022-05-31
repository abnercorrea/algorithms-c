//
// Created by Abner Correa on 4/2/22.
//
#include <iostream>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int base10 = 0;

        for (int i = 0, len = s.length(); i < len; i++) {
            switch (s[i]) {
                case 'M':
                    base10 += 1000;

                    if (i < len - 1){
                        if (s[i + 1] == 'M') {
                            if (i < len - 2 && s[i + 2] == 'M') {
                                base10 += 2000;
                                i += 2;
                            }
                            else {
                                base10 += 1000;
                                i++;
                            }
                        }
                    }
                    break;
                case 'D':
                    base10 += 500;
                    break;
                case 'C':
                    base10 += 100;

                    if (i < len - 1){
                        if (s[i + 1] == 'M') {
                            base10 += 800;
                            i++;
                        }
                        else if (s[i + 1] == 'D') {
                            base10 += 300;
                            i++;
                        }
                        else if (s[i + 1] == 'C') {
                            if (i < len - 2 && s[i + 2] == 'C') {
                                base10 += 200;
                                i += 2;
                            }
                            else {
                                base10 += 100;
                                i++;
                            }
                        }
                    }
                    break;
                case 'L':
                    base10 += 50;
                    break;
                case 'X':
                    base10 += 10;

                    if (i < len - 1){
                        if (s[i + 1] == 'C') {
                            base10 += 80;
                            i++;
                        }
                        else if (s[i + 1] == 'L') {
                            base10 += 30;
                            i++;
                        }
                        else if (s[i + 1] == 'X') {
                            if (i < len - 2 && s[i + 2] == 'X') {
                                base10 += 20;
                                i += 2;
                            }
                            else {
                                base10 += 10;
                                i++;
                            }
                        }
                    }
                    break;
                case 'V':
                    base10 += 5;
                    break;
                case 'I':
                    base10 += 1;
                    if (i < len - 1){
                        if (s[i + 1] == 'X') {
                            base10 += 8;
                            i++;
                        }
                        else if (s[i + 1] == 'V') {
                            base10 += 3;
                            i++;
                        }
                        else if (s[i + 1] == 'I') {
                            if (i < len - 2 && s[i + 2] == 'I') {
                                base10 += 2;
                                i += 2;
                            }
                            else {
                                base10 += 1;
                                i++;
                            }
                        }
                    }
            }
        }

        return base10;
    }
};