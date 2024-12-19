#include <iostream>
#include <vector>

using namespace std;

int maxChunksToSorted(vector<int>& arr) {
    int max = 0;

    int chunks = 0;

    int n = arr.size();

    for(int i = 0; i < n; ++i) {
        if(arr[i] > max) {
            max = arr[i];
        }

        if(max == i) {
            ++chunks;
        }
    }

    return chunks;
}

void test(vector<int> arr, int expected) {
    cout << "Input: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxChunksToSorted(arr) << endl;

    cout << endl;
}

int main() {
    vector<int> arr1 = {4, 3, 2, 1, 0};
    test(arr1, 1);

    vector<int> arr2 = {1, 0, 2, 3, 4};
    test(arr2, 4);

    vector<int> arr3 = {2, 0, 1};
    test(arr3, 1);

    vector<int> arr4 = {1, 2, 0, 3};
    test(arr4, 2);

    vector<int> arr5 = {0, 1, 2, 3, 4};
    test(arr5, 5);

    vector<int> arr6 = {0};
    test(arr6, 1);

    return 0;
}
