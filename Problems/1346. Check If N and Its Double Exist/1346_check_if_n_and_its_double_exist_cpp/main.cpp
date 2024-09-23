#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool checkIfExist(vector<int>& arr) {
    unordered_set<int> found;

    for(int i = arr.size() - 1; i > -1; --i) {
        if((found.find(2 * arr[i]) != found.end()) || (arr[i] % 2 == 0 && found.find(arr[i] / 2) != found.end())) {
            return true;
        }

        found.insert(arr[i]);
    }

    return false;
}

void runTestCase(vector<int> arr, bool expected) {
    cout << "Input: [";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i != arr.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (checkIfExist(arr) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    runTestCase({10, 2, 5, 3}, true);

    runTestCase({7, 1, 14, 11}, true);

    runTestCase({3, 1, 7, 11}, false);

    runTestCase({0, 0}, true);

    runTestCase({-2, 0, 10, -19, 4, 6, -8}, false);

    runTestCase({0}, false);

    return 0;
}
