#include <iostream>
#include <vector>

using namespace std;

vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
    int occurences = 0;

    int n = nums.size();
    for(int i = 0; i < n; ++i) {
        if(nums[i] == x) {
            nums[occurences++] = i;
        }
    }

    for(n = queries.size() - 1; n > -1; --n) {
        queries[n] = queries[n] > occurences ? -1 : nums[--queries[n]];
    }

    return queries;
}

void test(vector<int> nums, vector<int> queries, int x, vector<int> expected) {
    cout << "Input: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Queries: ";
    for (int query : queries) {
        cout << query << " ";
    }
    cout << endl;

    cout << "x: " << x << endl;

    cout << "Expected: ";
    for (int e : expected) {
        cout << e << " ";
    }
    cout << endl;

    cout << "Result: ";
    for (int result : occurrencesOfElement(nums, queries, x)) {
        cout << result << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    test({1, 2, 3, 4, 2, 5, 2}, {1, 2, 3, 4}, 2, {1, 4, 6, -1});
    test({5, 5, 5, 1, 2}, {1, 2, 3}, 5, {0, 1, 2});
    test({3, 3, 3, 3}, {1, 2, 5}, 3, {0, 1, -1});
    test({1, 2, 3, 4, 5}, {1, 1}, 6, {-1, -1});
    test({1, 1, 1, 2, 2, 3}, {1, 2, 3}, 1, {0, 1, 2});
    test({4, 4, 4, 4, 4}, {3, 5, 6}, 4, {2, 4, -1});
    test({1,2,3}, {10}, 5, {-1});

    return 0;
}
