//
// Created by Abner Correa on 2/27/22.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void test_ref_pointer(int a, int &b, int *c) {
    a = 0;
    b = 0;
    *c = 0;
}

template <class c>
int binarySearch(vector<c> a, c key) {
    int start = 0, end = a.size() - 1;

    while (start <= end) {
        int mid = (start + end) / 2;
        if (a[mid] == key) {
            return mid;
        }
        else if (a[mid] < key) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return start;
}

class Test {
public:
    int a;
};

void testPointer(Test **x) {
    Test t = Test();
    t.a = 37;
    *x = &t;
}

int main() {
    cout << "Hello World" << "\n";

    Test *t1 = nullptr;
    testPointer(&t1);
    cout << t1->a << "\n";

    vector<int> a = {1, 3, 5, 6};
    vector<string> b(10);
    int c[] = {10,11, 12, 13};

    for (int i = 0; i < b.size(); i++) {
        b[i] = "Person " + to_string(i);
    }

    cout << binarySearch(a, 4) << "\n";

    auto pos = find(a.begin(), a.end(), 5);
    if (pos != a.end()) {
        cout << "Pos of 5: " << (pos - a.begin()) << "\n";
    }
    else {
        cout << "not found!";
    }

    for (const int i: a) cout << i << "\n";

    for (int i = 0; i < b.size(); i++) {
        if (i % 2 == 0) {
            continue;
        }
        if (i > 7) {
            break;
        }
        cout << b[i] << "\n";
    }

    sort(
            a.begin(),
            a.end(),
            [](const int i1, const int i2) {
                return i1 > i2;
            }
    );

    cout << "a sorted: " << "\n";
    for (const int i: a) cout << i << "\n";

    int size_c = sizeof(c) / sizeof(c[0]);

    cout << "Size(c) = " << size_c << "\n";

    // Functor
    transform(
            c,
            c + 4,
            c,
            [](const int i) { return i * i; }
            );

    for (const int i: c) cout << i << "\n";

    cout << "c[1] = " << *(c + 1) << "\n";

    int x[] = {20, 21, 22};

    for (const int i: x) cout << i << "\n";
    cout << "Test pointer ref\n";
    test_ref_pointer(x[0], x[1], &x[2]);
    for (const int i: x) cout << i << "\n";

    int z = 10;
    do {
        cout << z-- << "\n";
    }
    while (z > 0);

    return 0;
}
