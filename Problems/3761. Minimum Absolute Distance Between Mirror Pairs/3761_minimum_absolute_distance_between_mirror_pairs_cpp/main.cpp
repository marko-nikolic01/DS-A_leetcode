#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int minMirrorPairDistance(vector<int>& nums) {
    int distance = nums.size();
    unordered_map<int, int> reversed;
    int reversedNumber;

    int n = distance;
    for(int i = 0; i < n; ++i) {
        if(reversed.find(nums[i]) != reversed.end()) {
            reversedNumber = reversed[nums[i]];

            if(i - reversedNumber < distance) {
                distance = i - reversedNumber;
            }
        }

        reversedNumber = 0;

        while(nums[i] > 0) {
            reversedNumber = 10 * reversedNumber + nums[i] % 10;
            nums[i] /= 10;
        }

        reversed[reversedNumber] = i;
    }

    return distance == n ? -1 : distance;
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

    cout << "Result: " << minMirrorPairDistance(nums) << endl;

    cout << endl;
}

int main() {
    test({12, 21, 45, 33, 54}, 1);
    test({120, 21}, 1);
    test({21, 120}, -1);
    test({33, 121, 33, 121, 99}, 2);
    test({13, 31, 99, 31}, 1);

    return 0;
}
