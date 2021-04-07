#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

vector<string> split_string(string);

int findInsertPos(vector<int> A, int e) {
    int start = 0, end = A.size() - 1;
    
    while (start <= end) {
        int pivot = (start + end) / 2;
        if (A[pivot] > e) {
            end = pivot - 1;
        } 
        else if (A[pivot] < e) {
            start = pivot + 1;
        }
        else {
            return pivot;
        }
    }
    return start;    
}

void insertOrdered(vector<int> &A, int e) {
    int insertPos = findInsertPos(A, e);
    A.resize(A.size() + 1);
    for(int j = A.size() - 1; j > insertPos; j--) {
        A[j] = A[j - 1];
    }
    A[insertPos] = e;
}

/*
 * Complete the cookies function below.
 */
int cookies(int k, vector<int> A) {
    /*
     * Write your code here.
     */
    priority_queue <int, vector<int>, greater<int>> pq;
    for (int a: A) {
        pq.push(a);
    }
    int steps = 0;
    for (int least = pq.top(); pq.size() > 1 && least < k; least = pq.top(), steps++) {
        pq.pop();
        int secondLeast = pq.top();
        pq.pop();        
        int combined = least + 2 * secondLeast;
        pq.push(combined);
    }
    return pq.top() >= k ? steps : -1;
}

int cookiesSlow(int k, vector<int> A) {
    /*
     * Write your code here.
     */
    sort(A.begin(), A.end());
    int steps = 0;
    for (; A.size() > 1 && A[0] < k; steps++) {
        int combined = A[0] + 2 * A[1];
        A.erase(A.begin());    
        A.erase(A.begin());
        insertOrdered(A, combined);
    }
    return A[0] >= k ? steps : -1;
}


int main()
{
    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string A_temp_temp;
    getline(cin, A_temp_temp);

    vector<string> A_temp = split_string(A_temp_temp);

    vector<int> A(n);

    for (int A_itr = 0; A_itr < n; A_itr++) {
        int A_item = stoi(A_temp[A_itr]);

        A[A_itr] = A_item;
    }

    int result = cookies(k, A);

    cout << result << "\n";

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
