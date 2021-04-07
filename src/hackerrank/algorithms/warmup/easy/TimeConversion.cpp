#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    /*
     * Write your code here.
     */
    bool pm = s.substr(8, 2) == "PM";
    short hour = stoi(s.substr(0, 2));
    if (pm && hour < 12) {
        hour += 12;
    }
    else if (! pm && hour == 12) {
        hour = 0;    
    }
    string minAndSec = s.substr(2, 6);
    char time[9];
    sprintf(time, "%02d%s", hour, minAndSec.c_str());
    return time;
}

int main()
{
    string s;
    getline(cin, s);

    string result = timeConversion(s);

    cout << result << "\n";

    return 0;
}
