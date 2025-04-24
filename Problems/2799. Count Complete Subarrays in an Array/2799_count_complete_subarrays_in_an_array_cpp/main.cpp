#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int countCompleteSubarrays(vector<int>& nums) {
    unordered_map<short, short> occurences;

    short i;
    short n = nums.size();
    for(i = 0; i < n; ++i) {
        occurences[nums[i]] = 0;
    }

    int subarrays = 0;
    short distinct = occurences.size();
    short currentDistinct = 0;

    for(i = --n; i > -1; --i) {
        if(++occurences[nums[i]] < 2) {
            if(++currentDistinct == distinct) {
                while(i <= n) {
                    subarrays += i + 1;

                    if(--occurences[nums[n--]] < 1) {
                        --currentDistinct;
                        break;
                    }
                }
            }
        }
    }

    return subarrays;
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

    cout << "Result: " << countCompleteSubarrays(nums) << endl;

    cout << endl;
}

int main() {
    test({1, 3, 1, 2, 2}, 4);
    test({5, 5, 5, 5}, 10);
    test({1, 2, 3}, 1);
    test({4, 4, 2, 4, 2}, 9);
    test({1, 2, 1, 3, 2, 3}, 8);

    return 0;
}
