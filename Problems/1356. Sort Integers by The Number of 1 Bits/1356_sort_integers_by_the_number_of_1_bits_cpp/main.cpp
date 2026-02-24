#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sortByBits(vector<int>& arr) {
    short n = arr.size();
    vector<pair<short, short>> ones(n, {0, 0});
    short number;

    for(short i = --n; i > -1; --i) {
        number = arr[i];
        ones[i].second = number;

        while(number > 0) {
            if((number & 1) > 0) {
                ++ones[i].first;
            }

            number >>= 1;
        }
    }

    sort(ones.begin(), ones.end());

    for(n; n > -1; --n) {
        arr[n] = ones[n].second;
    }

    return arr;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> arr, vector<int> expected) {
    cout << "Array: ";
    printArray(arr);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(sortByBits(arr));

    cout << endl;
}

int main() {
    test({0, 1, 2, 3, 4, 5, 6, 7, 8}, {0, 1, 2, 4, 8, 3, 5, 6, 7});
    test({1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1}, {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024});
    test({10000, 10000}, {10000, 10000});
    test({2, 3, 5, 7, 11, 13, 17, 19}, {2, 3, 5, 17, 7, 11, 13, 19});
    test({1, 5, 3, 7, 15, 31}, {1, 3, 5, 7, 15, 31});

    return 0;
}
