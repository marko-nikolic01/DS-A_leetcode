#include <iostream>
#include <vector>

using namespace std;

bool checkPrimeFrequency(vector<int>& nums) {
    vector<bool> primes(101, true);
    primes[0] = false;
    primes[1] = false;

    short i = 1;
    short j;
    while(++i < 101) {
        if(primes[i]) {
            for(j = i << 1; j < 101; j += i) {
                primes[j] = false;
            }
        }
    }

    vector<short> occurences(101, 0);
    j = 0;

    for(i = nums.size() - 1; i > -1; --i) {
        if(primes[occurences[nums[i]]]) {
            --j;
        }

        if(primes[++occurences[nums[i]]]) {
            ++j;
        }
    }

    return j > 0;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, bool expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (checkPrimeFrequency(nums) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({1, 2, 3, 4, 5, 4}, true);
    test({1, 2, 3, 4, 5}, false);
    test({2, 2, 2, 4, 4}, true);
    test({3, 0, 3, 6, 3, 3}, false);
    test({5, 5, 5, 5, 5, 5, 5}, true);
    test({1}, false);

    return 0;
}
