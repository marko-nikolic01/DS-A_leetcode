#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int minJumps(vector<int>& nums) {
    static vector<int> factors[1000001];
    static bool initialized = [&]() {
        for (int i = 2; i < 1000001; ++i) {
            if (factors[i].empty()) {
                for (int j = i; j < 1000001; j += i) {
                    factors[j].push_back(i);
                }
            }
        }
        return true;
    }();

    int n = nums.size();
    unordered_map<int, vector<int>> edges;
    for (int i = 0; i < n; ++i) {
        for (int p : factors[nums[i]]) {
            edges[p].push_back(i);
        }
    }
    int res = 0;
    vector<bool> seen(n, false);
    seen[0] = true;
    vector<int> q = {0};
    while (true) {
        vector<int> q2;
        for (int i : q) {
            if (i == n - 1) return res;
            if (i > 0 && !seen[i - 1]) {
                seen[i - 1] = true;
                q2.push_back(i - 1);
            }
            if (i < n - 1 && !seen[i + 1]) {
                seen[i + 1] = true;
                q2.push_back(i + 1);
            }
            if (factors[nums[i]].size() == 1) {
                int p = nums[i];
                if (edges.count(p)) {
                    for (int j : edges[p]) {
                        if (!seen[j]) {
                            seen[j] = true;
                            q2.push_back(j);
                        }
                    }
                    edges[p].clear();
                }
            }
        }
        q = move(q2);
        res++;
    }
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

    cout << "Result: " << minJumps(nums) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 4, 6}, 2);
    test({2, 3, 4, 7, 9}, 2);
    test({4, 6, 5, 8}, 3);
    test({1}, 0);
    test({1, 2}, 1);

    return 0;
}
