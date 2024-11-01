#include <iostream>
#include <vector>

using namespace std;

vector<int> findArray(vector<int>& pref) {
    int n = pref.size();

    int xorSum = pref[0];

    for(int i = 1; i < n; ++i) {
        pref[i] = xorSum ^ pref[i];
        xorSum ^= pref[i];
    }

    return pref;
}

void test(vector<int> pref, vector<int> expected) {
    cout << "Input: ";
    for (int val : pref) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Expected: ";
    for (int val : expected) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Result: ";
    for (int val : findArray(pref)) {
        cout << val << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    test({5, 2, 0, 3, 1}, {5, 7, 2, 3, 2});
    test({13, 10, 5, 9, 12}, {13, 7, 15, 12, 5});
    test({1, 3, 6, 10, 15}, {1, 2, 5, 12, 5});
    test({0}, {0});
    test({4, 4, 4, 4}, {4, 0, 0, 0});
    test({0, 0, 0, 0, 0}, {0, 0, 0, 0, 0});

    return 0;
}
