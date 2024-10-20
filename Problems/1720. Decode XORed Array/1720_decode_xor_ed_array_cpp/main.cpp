#include <iostream>
#include <vector>

using namespace std;

vector<int> decode(vector<int>& encoded, int first) {
    int currentEncoded = encoded[0];

    int n = encoded.size();
    for(int i = 1; i < n; ++i) {
        encoded[i - 1] = first;
        first ^= currentEncoded;
        currentEncoded = encoded[i];
    }

    encoded[--n] = first;
    encoded.push_back(first ^ currentEncoded);

    return encoded;
}
void runTestCase(vector<int> encoded, int first, vector<int> expected) {
    cout << "Encoded: ";
    for (int num : encoded) {
        cout << num << " ";
    }
    cout << endl;

    cout << "First: " << first << endl;

    cout << "Expected: ";
    for (int num : expected) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Result: ";
    for (int num : decode(encoded, first)) {
        cout << num << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    runTestCase({1, 2, 3}, 0, {0, 1, 3, 0});
    runTestCase({6, 5, 4}, 2, {2, 4, 1, 5});
    runTestCase({3, 2, 1}, 5, {5, 6, 4, 5});
    runTestCase({1, 0, 2, 1}, 4, {4, 5, 5, 7, 6});
    runTestCase({0, 0, 0}, 0, {0, 0, 0, 0});
    runTestCase({0, 1, 0}, 1, {1, 1, 0, 0});

    return 0;
}
