#include <iostream>
#include <vector>

using namespace std;

vector<int> getSneakyNumbers(vector<int>& nums) {
    short n = nums.size() - 2;
    vector<bool> seen(n, false);
    vector<int> duplicates(2);
    short duplicate = 1;

    for(++n; n > -1; --n) {
        if(seen[nums[n]]) {
            duplicates[duplicate] = nums[n];

            if(--duplicate < 0) {
                break;
            }
        } else {
            seen[nums[n]] = true;
        }
    }

    return duplicates;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, vector<int> expected) {
    cout << "Numbers: ";
    printArray(nums);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(getSneakyNumbers(nums));

    cout << endl;
}

int main() {
    test({0, 1, 1, 0}, {0, 1});
    test({0, 3, 2, 1, 3, 2}, {3, 2});
    test({7, 1, 5, 4, 3, 4, 6, 0, 9, 5, 8, 2}, {5, 4});
    test({0, 2, 4, 1, 3, 2, 5, 5}, {2, 5});
    test({6, 0, 4, 1, 3, 2, 4, 5, 6}, {6, 4});

    return 0;
}
