#include <iostream>
#include <vector>

using namespace std;

int longestNiceSubarray(vector<int>& nums) {
    int length = 1;
    int bits = 0;

    int right = nums.size();
    for(int left = --right; left > -1; --left) {
        while((nums[left] & bits) > 0) {
            bits ^= nums[right--];
        }

        if(right - left + 1 > length) {
            length = right - left + 1;
        }

        bits |= nums[left];
    }

    return length;
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

    cout << "Result: " << longestNiceSubarray(nums) << endl;

    cout << endl;
}

int main() {
    test({1, 3, 8, 48, 10}, 3);
    test({3, 1, 5, 11, 13}, 1);
    test({32150781, 87893694, 864468575, 193900026, 536907831, 539335608, 296179991, 571627154, 590957801}, 1);
    test({8, 4096, 524288, 16777216, 2097152, 1024, 4194304, 32768, 1048576, 65536, 4, 536870912, 1, 134217728, 128, 256, 8388608, 2, 8192, 2048, 16384, 16, 64, 33554432, 131072, 512, 262144, 32, 67108864}, 29);
    test({45106826, 547958667, 823366125, 332020148, 611677524, 510346561, 555831456, 436600904, 12594192, 127206768, 540754485, 201997978, 473116514, 233000361, 538246458, 729745279, 343417143, 892046691, 376031730}, 3);
    test({744437702, 379056602, 145555074, 392756761, 560864007, 934981918, 113312475, 1090, 16384, 33, 217313281, 117883195, 978927664}, 3);

    return 0;
}
