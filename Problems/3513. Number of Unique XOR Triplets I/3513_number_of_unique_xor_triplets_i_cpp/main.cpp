#include <iostream>
#include <vector>

using namespace std;

int uniqueXorTriplets(vector<int>& nums) {
    int n = nums.size();
    if(n < 3) {
        return n;
    }

    int triplets = 1;

    while(triplets <= n) {
        triplets <<= 1;
    }

    return triplets;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int expected) {
    cout << "Tree: ";
    printArray(nums);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << uniqueXorTriplets(nums) << endl;

    cout << endl;
}

int main() {
    test({1, 2}, 2);
    test({3, 1, 2}, 4);
    test({1}, 1);
    test({1, 2, 3, 4}, 8);
    test({5, 3, 1, 2, 4}, 8);

    return 0;
}
