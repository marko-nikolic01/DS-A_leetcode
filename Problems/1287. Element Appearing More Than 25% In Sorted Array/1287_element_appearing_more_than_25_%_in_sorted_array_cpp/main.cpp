#include <iostream>
#include <vector>

using namespace std;

int findSpecialInteger(vector<int>& arr) {
    int n = arr.size();

    int quarter = n / 4;

    for(int i = 0; i < n; ++i) {
        if(arr[i] == arr[i + quarter]) {
            return arr[i];
        }

        i += quarter;
        while(i > 0 && arr[i] == arr[i - 1]) {
            i--;
        }
        i--;
    }

    return 0;
}

void test(vector<int>& arr, int expected) {
    cout << "Input: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << findSpecialInteger(arr) << endl;

    cout << endl;
}

int main() {
    vector<int> test1 = {1, 2, 2, 2, 3};
    test(test1, 2);

    vector<int> test2 = {1, 1, 2, 2, 2, 2, 3, 3};
    test(test2, 2);

    vector<int> test3 = {1, 1, 1, 2, 2, 3, 3, 3, 3};
    test(test3, 1);

    vector<int> test4 = {1, 1, 1, 1};
    test(test4, 1);

    vector<int> test5 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 9, 9, 9, 9, 10};
    test(test5, 9);

    vector<int> test6 = {1};
    test(test6, 1);

    return 0;
}
