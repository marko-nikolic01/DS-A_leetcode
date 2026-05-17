#include <iostream>
#include <vector>

using namespace std;

bool canReach(vector<int>& arr, int start) {
    vector<unsigned short> traversal(1, start);

    arr[start] = -arr[start];

    unsigned short n = arr.size();
    while(!traversal.empty()) {
        start = traversal.back();
        traversal.pop_back();

        if(arr[start] > -1) {
            return true;
        }

        if(start >= -arr[start] && arr[start + arr[start]] > -1) {
            arr[start + arr[start]] = -arr[start + arr[start]];
            traversal.push_back(start + arr[start]);
        }

        if(start - arr[start] < n && arr[start - arr[start]] > -1) {
            arr[start - arr[start]] = -arr[start - arr[start]];
            traversal.push_back(start - arr[start]);
        }
    }

    return false;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> arr, int start, bool expected) {
    cout << "Array: ";
    printArray(arr);

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (canReach(arr, start) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({4, 2, 3, 0, 3, 1, 2}, 5, true);
    test({4, 2, 3, 0, 3, 1, 2}, 0, true);
    test({3, 0, 2, 1, 2}, 2, false);
    test({0, 1}, 0, true);
    test({1, 2, 3, 4, 5}, 0, false);

    return 0;
}
