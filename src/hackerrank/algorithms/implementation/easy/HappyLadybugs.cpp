#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// Complete the happyLadybugs function below.
string happyLadybugs(string b) {
    vector<int> colorCount('Z' - 'A' + 1);
    int empty = 0;
    bool allHappy = true, singleColor;
    
    for (int i = 0, n = b.length(); i < n; i++) {
        char before = (i == 0) ? ' ' : b[i - 1];
        char after = (i == n - 1) ? ' ' : b[i + 1];         
        allHappy &= before == b[i] || b[i] == after;
            
        if (b[i] == '_'){
            empty++;
        }
        else {
            colorCount[b[i] - 'A']++;
        }
    }

    for (int i = 0, n = colorCount.size(); i < n && ! singleColor; i++)
        singleColor = colorCount[i] == 1;
    
    return allHappy || (!singleColor && empty > 0) ? "YES" : "NO";
}

int main()
{
    int g;
    cin >> g;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int g_itr = 0; g_itr < g; g_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string b;
        getline(cin, b);

        string result = happyLadybugs(b);

        cout << result << "\n";
    }

    return 0;
}
