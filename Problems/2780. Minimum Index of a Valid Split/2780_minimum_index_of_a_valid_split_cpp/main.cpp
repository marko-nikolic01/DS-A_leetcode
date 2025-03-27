#include <iostream>
#include <vector>

using namespace std;

int minimumIndex(vector<int>& nums) {
    int dominantElement = nums[0];
    int dominantCount = 1;

    int i = 1;
    int n = nums.size();
    for(i; i < n; ++i) {
        if(nums[i] == dominantElement) {
            ++dominantCount;
        } else if(--dominantCount < 1) {
            dominantElement = nums[i];
            dominantCount = 1;
        }
    }

    dominantCount = 0;

    for(i = 0; i < n; ++i) {
        if(nums[i] == dominantElement) {
            ++dominantCount;
        }
    }

    int currentDominantCount = 0;

    for(i = 0; i < n; ++i) {
        if(nums[i] == dominantElement) {
            ++currentDominantCount;
            --dominantCount;
        }

        if(currentDominantCount << 1 > i + 1 && dominantCount << 1 > n - i - 1) {
            return i;
        }
    }

    return -1;
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

    cout << "Result: " << minimumIndex(nums) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 2, 2}, 2);
    test({2, 1, 3, 1, 1, 1, 7, 1, 2, 1}, 4);
    test({3, 3, 3, 3, 7, 2, 2}, -1);
    test({1, 1}, 0);
    test({1, 7, 9, 8, 7, 7, 7, 7, 7, 2}, 6);
    test({4, 4, 4, 5, 6, 4, 4, 4, 4}, 0);

    return 0;
}
