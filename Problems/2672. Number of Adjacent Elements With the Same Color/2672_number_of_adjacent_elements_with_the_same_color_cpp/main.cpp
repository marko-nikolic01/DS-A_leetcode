#include <iostream>
#include <vector>

using namespace std;

vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
    vector<int> result;
    vector<int> nums(n--, 0);
    int c = 0;
    int index;
    int color;
    int previous;
    int next;

    int m = queries.size();
    for(int i = 0; i < m; ++i) {
        index = queries[i][0];
        color = queries[i][1];
        previous = index > 0 ? nums[index - 1] : 0;
        next = index < n ? nums[index + 1] : 0;

        if(nums[index] > 0 && nums[index] == previous) {
            --c;
        }

        if(nums[index] > 0 && nums[index] == next) {
            --c;
        }

        nums[index] = color;

        if(nums[index] == previous) {
            ++c;
        }

        if(nums[index] == next) {
            ++c;
        }

        result.push_back(c);
    }

    return result;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(int n, vector<vector<int>> queries, vector<int> expected) {
    cout << "n: " << n << endl;

    cout << "Queries: ";
    for(vector<int> query : queries) {
        cout << "[" << query[0] << ", " << query[1] << "]";
    }
    cout << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(colorTheArray(n, queries));

    cout << endl;
}

int main() {
    test(4, {{0, 2}, {1, 2}, {3, 1}, {1, 1}, {2, 1}}, {0, 1, 1, 0, 2});
    test(1, {{0, 100000}}, {0});
    test(3, {{0, 1}, {1, 1}, {2, 1}}, {0, 1, 2});
    test(5, {{2, 3}, {3, 3}}, {0, 1});
    test(2, {{0, 5}, {1, 5}}, {0, 1});
    return 0;
}
