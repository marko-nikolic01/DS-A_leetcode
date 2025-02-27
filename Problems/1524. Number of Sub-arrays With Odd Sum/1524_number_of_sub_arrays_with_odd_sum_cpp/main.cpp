#include <iostream>
#include <vector>

using namespace std;

int numOfSubarrays(vector<int>& arr) {
    int odd = 0;

    int currentOdd = 0;
    int currentEven = 0;
    int previousOdd;

    for(int i = arr.size() - 1; i > -1; --i) {
        if((arr[i] & 1) > 0) {
            previousOdd = currentOdd;
            currentOdd = ++currentEven;
            currentEven = previousOdd;
        } else {
            ++currentEven;
        }

        odd = (odd + currentOdd) % 1000000007;
    }

    return odd;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numOfSubarrays(nums) << endl;

    cout << endl;
}

int main() {
    test({1, 3, 5}, 4);
    test({2, 4, 6}, 0);
    test({1, 2, 3, 4, 5, 6, 7}, 16);
    test({1}, 1);
    test({2}, 0);
    test({7, 2, 5, 8, 1}, 9);
    test({4, 9, 6, 3, 1}, 9);

    return 0;
}
