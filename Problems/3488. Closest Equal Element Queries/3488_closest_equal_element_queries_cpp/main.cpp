#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
    int n = nums.size();
    vector<int> left(n);
    vector<int> right(n);
    unordered_map<int, int> position;

    int i;
    for(i = -n; i < n; ++i) {
        if(i > -1) {
            left[i] = position[nums[i]];
        }

        position[nums[(i + n) % n]] = i;
    }

    position.clear();

    for(i = (n << 1) - 1; i > -1; --i) {
        if(i < n) {
            right[i] = position[nums[i]];
        }

        position[nums[i % n]] = i;
    }

    int m = queries.size();
    for(i = 0; i < m; ++i) {
        queries[i] = queries[i] - left[queries[i]] == n ? -1 : min(queries[i] - left[queries[i]], right[queries[i]] - queries[i]);
    }

    return queries;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, vector<int> queries, vector<int> expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Queries: ";
    printArray(queries);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(solveQueries(nums, queries));

    cout << endl;
}

int main() {
    test({1, 3, 1, 4, 1, 3, 2}, {0, 3, 5}, {2, -1, 3});
    test({1, 2, 3, 4}, {0, 1, 2, 3}, {-1, -1, -1, -1});
    test({5, 5, 5, 5, 5}, {0, 1, 2, 3, 4}, {1, 1, 1, 1, 1});
    test({7, 1, 2, 3, 7}, {0, 4}, {1, 1});
    test({42}, {0}, {-1});

    return 0;
}
