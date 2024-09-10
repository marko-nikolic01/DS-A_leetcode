#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    if(n < 2) {
        return nums[0];
    } else if(n > 2) {
        nums[n - 3] += nums[n - 1];
    }

    for(n -= 4; n > -1; --n) {
        nums[n] += nums[n + 2] > nums[n + 3] ? nums[n + 2] : nums[n + 3];
    }

    return nums[0] > nums[1] ? nums[0] : nums[1];
}

void printResult(vector<int> houses, int expected) {
    cout << "Houses: ";
    for (int money : houses) {
        cout << money << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << rob(houses) << endl;

    cout << endl;
}

int main() {
    printResult({1, 2, 3, 1}, 4);
    printResult({2, 7, 9, 3, 1}, 12);
    printResult({2, 1, 1, 2}, 4);
    printResult({5, 3, 4, 11, 2}, 16);
    printResult({2}, 2);
    printResult({1, 2}, 2);

    return 0;
}
