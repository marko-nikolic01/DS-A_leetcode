#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
    int group = -1;
    int value = INT_MAX;

    while(--n > -1) {
        if(value - nums[n] > maxDiff) {
            ++group;
        }

        value = nums[n];
        nums[n] = group;
    }

    n = queries.size();
    vector<bool> answers(n);

    while(--n > -1) {
        answers[n] = nums[queries[n][0]] == nums[queries[n][1]];
    }

    return answers;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void printArray(vector<bool> array) {
    for(bool a : array) {
        cout << (a ? "true" : "false") << " ";
    }
    cout << endl;
}

void test(int n, vector<int> nums, int maxDiff, vector<vector<int>> queries, vector<bool> expected) {
    cout << "n: " << n << endl;

    cout << "Nodes: ";
    printArray(nums);

    cout << "Maximum difference: " << maxDiff << endl;

    cout << "Queries: ";
    for(vector<int> query : queries) {
        cout << "[" << query[0] << ", " << query[1] << "] ";
    }
    cout << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(pathExistenceQueries(n, nums, maxDiff, queries));

    cout << endl;
}

int main() {
    test(2, {1, 3}, 1, {{0, 0}, {0, 1}}, {true, false});
    test(4, {2, 5, 6, 8}, 2, {{0, 1}, {0, 2}, {1, 3}, {2, 3}}, {false, false, true, true});
    test(1, {5}, 0, {{0, 0}}, {true});
    test(5, {1, 2, 3, 4, 5}, 1, {{0, 4}, {0, 2}, {2, 4}}, {true, true, true});
    test(3, {0, 100000, 100000}, 100000, {{0, 1}, {0, 2}, {1, 2}}, {true, true, true});

    return 0;
}
