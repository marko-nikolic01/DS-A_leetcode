#include <iostream>
#include <vector>

using namespace std;

bool doesValidArrayExist(vector<int>& derived) {
    for(int i = derived.size() - 1; i > 0; --i) {
        derived[0] ^= derived[i];
    }

    return derived[0] == 0;
}

void test(int testCaseNumber, vector<int> derived, bool expected) {
    cout << "Derived: ";
    for(int val : derived) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (doesValidArrayExist(derived) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test(1, {1, 1, 0}, true);
    test(2, {1, 1}, true);
    test(3, {1, 0}, false);
    test(4, {0}, true);
    test(5, {1, 0, 1}, true);
    test(6, {0, 0, 0}, true);
    test(7, {1, 1, 1}, false);

    return 0;
}
