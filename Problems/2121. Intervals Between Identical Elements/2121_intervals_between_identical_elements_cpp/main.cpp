#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<long long> getDistances(vector<int>& arr) {
    int n = arr.size();
    vector<long long> intervals(n);
    unordered_map<int, tuple<int, long, int, long>> sums;

    for(int i = 0; i < n; ++i) {
        ++get<0>(sums[arr[i]]);
        get<1>(sums[arr[i]]) += i;
    }

    unordered_map<int, tuple<int, long, int, long>>::iterator it;
    while(--n > -1) {
        it = sums.find(arr[n]);
        --get<0>(it->second);
        ++get<2>(it->second);
        get<1>(it->second) -= n;
        get<3>(it->second) += n;
        intervals[n] = (long)(get<0>(it->second) - get<2>(it->second)) * n - get<1>(it->second) + get<3>(it->second);
    }

    return intervals;
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

void test(vector<int> nums, vector<long long> expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(getDistances(nums));

    cout << endl;
}

int main() {
    test({2, 1, 3, 1, 2, 3, 3}, {4, 2, 7, 2, 4, 4, 5});
    test({10, 5, 10, 10}, {5, 0, 3, 4});
    test({1, 3, 1, 1, 2}, {5, 0, 3, 4, 0});
    test({0, 5, 3}, {0, 0, 0});
    test({2, 2, 2, 2}, {6, 4, 4, 6});
    test({1, 2, 1, 2, 1}, {6, 2, 4, 2, 6});
    test({7}, {0});

    return 0;
}
