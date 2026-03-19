#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class UnionFind {
    private:
        vector<int> parent;

    public:
        UnionFind(int n) {
            parent.resize(n);

            for(int i = 0; i < n; ++i) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if(x == parent[x]) {
                return x;
            }

            parent[x] = find(parent[x]);

            return parent[x];
        }

        void findUnion(int u, int v) {
            int pu = find(u);
            int pv = find(v);

            if(pu != pv) {
                parent[pu] = pv;
            }
        }
};

void gcdSort(vector<int>& spf, int n) {
    spf.resize(n);

    int i;
    for(i = 2; i < n; ++i) {
        spf[i] = i;
    }

    int j;
    for(i = 2; i * i < n; i++) {
        if(spf[i] != i) {
            continue;
        }

        for(j = i * i; j < n; j += i) {
            if(spf[j] > i) {
                spf[j] = i;
            }
        }
    }
}

vector<int> gcdSort(int n, vector<int>& spf) {
    vector<int> factors;

    while(n > 1) {
        factors.push_back(spf[n]);
        n /= spf[n];
    }

    return factors;
}

bool gcdSort(vector<int>& nums) {
    vector<int> spf;
    vector<int> factors;
    int maxNum = *max_element(nums.begin(), nums.end());

    gcdSort(spf, ++maxNum);

    UnionFind uf(maxNum);

    int i;
    int j;
    int n = nums.size();
    int m;
    for(i = 0; i < nums.size(); ++i) {
        factors = gcdSort(nums[i], spf);

        m = factors.size();
        for(j = 0; j < m; ++j) {
            uf.findUnion(nums[i], factors[j]);
        }
    }

    vector<int> sortedArr(nums);

    sort(sortedArr.begin(), sortedArr.end());

    for(i = 0; i <n; ++i) {
        if(uf.find(nums[i]) != uf.find(sortedArr[i])) {
            return false;
        }
    }

    return true;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, bool expected) {
    cout << "Array:" << endl;
    printArray(nums);

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (gcdSort(nums) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({7, 21, 3}, true);
    test({5, 2, 6, 2}, false);
    test({10, 5, 9, 3, 15}, true);
    test({2, 3, 5, 7, 11}, true);
    test({7, 11, 13}, true);

    return 0;
}
