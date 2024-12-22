#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> products(n--);
    products[0] = nums[0];

    for(int i = 1; i < n; ++i) {
        products[i] = products[i - 1] * nums[i];
    }

    int product = 1;
    for(n; n > 0; --n) {
        products[n] = product * products[n - 1];
        product *= nums[n];
    }
    products[0] = product;

    return products;
}

void test(vector<int> nums, vector<int> expected) {
    cout << "Input: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: ";
    for (int e : expected) {
        cout << e << " ";
    }
    cout << endl;

    cout << "Result: ";
    for (int result : productExceptSelf(nums)) {
        cout << result << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    test({1, 2, 3, 4}, {24, 12, 8, 6});
    test({-1, 1, 0, -3, 3}, {0, 0, 9, 0, 0});
    test({2, 3, 4, 5}, {60, 40, 30, 24});
    test({1, 0}, {0, 1});
    test({0, 0}, {0, 0});
    test({1, 2, 3, 0, 4}, {0, 0, 0, 24, 0});

    return 0;
}
