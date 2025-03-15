#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minCapability(vector<int>& nums, int k) {
    int minR = 1, maxR = *max_element(nums.begin(), nums.end()), totalH = nums.size();

    while(minR < maxR) {
        int midR = (minR + maxR) / 2;
        int thefts = 0;

        for(int i = 0; i < totalH; ++i) {
            if(nums[i] <= midR) {
                ++i;
                ++thefts;
            }
        }

        if(thefts >= k) {
            maxR = midR;
        } else {
            minR = midR + 1;
        }
    }

    return minR;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int k, int expected) {
    cout << "Houses: ";
    printArray(nums);

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minCapability(nums, k) << endl;

    cout << endl;
}

int main() {
    test({2, 3, 5, 9}, 2, 5);
    test({2, 7, 9, 3, 1}, 2, 2);
    test({4, 4, 4, 4, 4}, 3, 4);
    test({1, 2, 3, 4, 5, 6, 7}, 3, 5);
    test({1}, 1, 1);

    return 0;
}
