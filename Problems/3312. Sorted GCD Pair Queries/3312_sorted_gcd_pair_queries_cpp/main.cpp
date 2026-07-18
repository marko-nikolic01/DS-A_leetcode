#include <iostream>
#include <vector>

using namespace std;

vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
    int maximum = nums[0];

    int i;
    int j = nums.size();
    for(i = --j; i > 0; --i) {
        if(nums[i] > maximum) {
            maximum = nums[i];
        }
    }

    vector<long> counts(++maximum);

    while(j > -1) {
        ++counts[nums[j--]];
    }

    for(i = 1; i < maximum; ++i) {
        for(j = i << 1; j < maximum; j += i) {
            counts[i] += counts[j];
        }
    }

    for(i = 1; i < maximum; ++i) {
        counts[i] = counts[i] * (counts[i] - 1) >> 1;
    }

    for(i = --maximum; i > 0; --i) {
        for(j = i << 1; j <= maximum; j += i) {
            counts[i] -= counts[j];
        }
    }

    for(i = 1; i <= maximum; ++i) {
        counts[i] += counts[i - 1];
    }

    i = queries.size();
    vector<int> answers(i);

    while(--i > -1) {
        answers[i] = lower_bound(counts.begin(), counts.end(), ++queries[i]) - counts.begin();
    }

    return answers;
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

void test(vector<int> nums, vector<long long> queries, vector<int> expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Queries: ";
    printArray(queries);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(gcdValues(nums, queries));

    cout << endl;
}

int main() {
    test({2, 3, 4}, {0, 2, 2}, {1, 2, 2});
    test({4, 4, 2, 1}, {5, 3, 1, 0}, {4, 2, 1, 1});
    test({2, 2}, {0, 0}, {2, 2});
    test({6, 10, 15}, {0, 1, 2}, {2, 3, 5});
    test({1, 1, 1, 1}, {0, 1, 2, 3, 4, 5}, {1, 1, 1, 1, 1, 1});

    return 0;
}
