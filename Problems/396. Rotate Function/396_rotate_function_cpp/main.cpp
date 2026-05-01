#include <iostream>
#include <vector>

using namespace std;

int maxRotateFunction(vector<int>& nums) {
    int f = 0;
    int currentF;
    int sum = 0;

    int i;
    int n = nums.size();
    for(i = 0; i < n; ++i) {
        sum += nums[i];
        f += i * nums[i];
    }

    currentF = f;

    while(--i > 0) {
        currentF += sum - n * nums[i];

        if(currentF > f) {
            f = currentF;
        }
    }

    return f;
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

    cout << "Result: " << maxRotateFunction(nums) << endl;

    cout << endl;
}

int main() {
    test({4, 3, 2, 6}, 26);
    test({100}, 0);
    test({2, 2, 2, 2}, 12);
    test({-1, -2, -3}, -5);
    test({1, 2, 3, 4, 5}, 40);

    return 0;
}
