#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
    int n = nums.size();
    vector<long long> ids(n);
    map<long, int> frequencies;
    unordered_map<int, long> numbers;

    for(int i = 0; i < n; ++i) {
        if(numbers[nums[i]] > 0 && --frequencies[numbers[nums[i]]] < 1) {
            frequencies.erase(numbers[nums[i]]);
        }

        numbers[nums[i]] += freq[i];
        ++frequencies[numbers[nums[i]]];
        ids[i] = frequencies.rbegin()->first;
    }

    return ids;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void printArray(vector<long long> array) {
    for(long long a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, vector<int> freq, vector<long long> expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Frequencies: ";
    printArray(freq);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(mostFrequentIDs(nums, freq));

    cout << endl;
}

int main() {
    test({2, 3, 2, 1}, {3, 2, -3, 1}, {3, 3, 2, 2});
    test({5, 5, 3}, {2, -2, 1}, {2, 0, 1});
    test({1, 2, 3, 2, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 2, 2});
    test({4, 4, 4, 4}, {5, -2, -2, -1}, {5, 3, 1, 0});
    test({10, 20, 10, 30, 20, 10}, {4, 3, -1, 5, -2, -3}, {4, 4, 3, 5, 5, 5});

    return 0;
}
