#include <iostream>
#include <vector>
#include <climits>

using namespace std;

long long maximumScore(vector<int>& nums) {
    long score = LLONG_MIN;
    long sum = 0;

    int i;
    int n = nums.size();
    for(i = n - 2; i > -1; --i) {
        sum += nums[i];
    }

    i = nums[--n];

    while(--n > -1) {
        if(sum - i > score) {
            score = sum - i;
        }

        sum -= nums[n];

        if(nums[n] < i) {
            i = nums[n];
        }
    }

    return score;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, long long expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maximumScore(nums) << endl;

    cout << endl;
}

int main() {
    test({10, -1, 3, -4, -5}, 17);
    test({-7, -5, 3}, -2);
    test({1, 1}, 0);
    test({5, 4, 3, 2, 1}, 13);
    test({-1, -2, -3, -4}, 3);

    return 0;
}
