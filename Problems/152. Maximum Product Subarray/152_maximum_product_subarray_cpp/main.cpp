#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void maxProduct(vector<int>& nums, int& minimumProduct, int& maximumProduct, int& nextMinimumProduct, int& nextMaximumProduct, int& product, short& i) {
    int product1 = nums[--i] * minimumProduct;
    int product2 = nums[i] * maximumProduct;

    nextMinimumProduct = min(nums[i], min(product1, product2));
    nextMaximumProduct = max(nums[i], max(product1, product2));

    if(nextMaximumProduct > product) {
        product = nextMaximumProduct;
    }

    if(i > 0) {
        maxProduct(nums, nextMinimumProduct, nextMaximumProduct, minimumProduct, maximumProduct, product, i);
    }
}

int maxProduct(vector<int>& nums) {
    int product = INT_MIN;
    int minimumProduct = 1;
    int maximumProduct = 1;
    int nextMinimumProduct;
    int nextMaximumProduct;
    short i = nums.size();

    maxProduct(nums, minimumProduct, maximumProduct, nextMinimumProduct, nextMaximumProduct, product, i);

    return product;
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

    cout << "Result: " << maxProduct(nums) << endl;

    cout << endl;
}

int main() {
    test({2, 3, -2, 4}, 6);
    test({-2, 0, -1}, 0);
    test({-3, 0, 1, -2}, 1);
    test({-2, 3, -4}, 24);
    test({0, 2}, 2);

    return 0;
}
