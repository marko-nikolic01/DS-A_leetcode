#include <iostream>
#include <vector>

using namespace std;

long long maxTotal(vector<int>& nums, string s) {
    long tokens = 0;

    int i;
    int n = nums.size();
    for(i = 0; i < n && s[i] > '0'; ++i) {
        tokens += nums[i];
    }

    int j;
    while(++i < n) {
        j = --i;
        while(++i < n && s[i] > '0') {
            if(nums[j] >= nums[i]) {
                tokens += nums[j];
                --s[i];

                break;
            }

            tokens += nums[i];
        }
    }

    return tokens;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, string s, long long expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Tokens: " << s << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxTotal(nums, s) << endl;

    cout << endl;
}

int main() {
    test({9, 2, 6, 1}, "0101", 15);
    test({5, 1, 4}, "001", 4);
    test({9, 3, 5}, "011", 14);
    test({3, 2}, "11", 5);
    test({10, 7, 3}, "110", 17);
    test({8}, "1", 8);

    return 0;
}
