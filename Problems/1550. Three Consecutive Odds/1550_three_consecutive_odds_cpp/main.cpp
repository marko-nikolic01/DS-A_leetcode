#include <iostream>
#include <vector>

using namespace std;

bool threeConsecutiveOdds(vector<int>& arr) {
    for(int i = arr.size() - 1; i > 1; --i) {
        if(arr[i] & 1 == 1 && arr[--i] & 1 == 1 && arr[--i] & 1 == 1) {
            return true;
        }
    }

    return false;
}

void test(vector<int> arr, bool expected) {
    cout << "Input: [";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i != arr.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (threeConsecutiveOdds(arr) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({2, 4, 1, 3, 5}, true);
    test({1, 2, 3, 4}, false);
    test({1, 3, 5, 7}, true);
    test({1, 2, 4, 5, 7}, false);
    test({10, 11, 13, 15, 17}, true);
    test({2, 6, 8, 4}, false);

    return 0;
}
