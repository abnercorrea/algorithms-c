#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// Complete the jimOrders function below.
vector<int> jimOrders(vector<vector<int>> orders) {
    for (int i = 0; i < orders.size(); i++) {
        orders[i].push_back(i + 1);
    }
    
    sort( 
        orders.begin( ),
        orders.end( ),
        // Lambda!
        [ ]( const vector<int> order1, const vector<int> order2) {
            int diff = order1[0] + order1[1] - order2[0] - order2[1];
            if (diff == 0) {
               return order1[2] < order2[2]; 
            }
            else {
               return diff < 0; 
            }
        }
    );

    vector<int> customers(orders.size());
    for (int i = 0; i < orders.size(); i++) {
        customers[i] = orders[i][2];
    }
    
    return customers;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> orders(n);
    for (int i = 0; i < n; i++) {
        orders[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> orders[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> result = jimOrders(orders);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << " ";
        }
    }

    cout << "\n";

    return 0;
}
