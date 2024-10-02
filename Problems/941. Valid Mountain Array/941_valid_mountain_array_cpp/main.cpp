#include <iostream>
#include <vector>

using namespace std;

bool validMountainArray(vector<int>& arr) {
    int n = arr.size();
    if(n < 3 || arr[0] >= arr[1]) {
        return false;
    }

    bool isAscending = true;

    for(int i = 2; i < n; ++i) {
        if(arr[i - 1] == arr[i]) {
            return false;
        }

        if(isAscending) {
            if(arr[i - 1] > arr[i]) {
                isAscending = false;
            }
        } else if(arr[i - 1] < arr[i]) {
            return false;
        }
    }

    return !isAscending;
}

void runTest(vector<int> mountain, bool expected) {
    bool result = validMountainArray(mountain);

    cout << "Mountain: [";
    for (int i = 0; i < mountain.size(); ++i) {
        cout << mountain[i];
        if (i != mountain.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (result ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    runTest({2, 1}, false);
    runTest({3, 5, 5}, false);
    runTest({0, 3, 2, 1}, true);
    runTest({0, 2, 3, 4, 5, 2, 1, 0}, true);
    runTest({0, 2, 3, 3, 5, 2, 1, 0}, false);
    runTest({9, 8, 7, 6, 5}, false);
    runTest({1, 3, 2}, true);
    runTest({1, 2, 3, 4, 5}, false);
    runTest({5, 4, 3, 2, 1}, false);

    return 0;
}
