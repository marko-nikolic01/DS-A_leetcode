#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<long long> distance(vector<int>& nums) {
    int n = nums.size();
    vector<long long> distances(n);
    unordered_map<int, tuple<int, long, int, long>> sums;

    for(int i = 0; i < n; ++i) {
        ++get<0>(sums[nums[i]]);
        get<1>(sums[nums[i]]) += i;
    }

    unordered_map<int, tuple<int, long, int, long>>::iterator it;
    while(--n > -1) {
        it = sums.find(nums[n]);
        --get<0>(it->second);
        ++get<2>(it->second);
        get<1>(it->second) -= n;
        get<3>(it->second) += n;
        distances[n] = (long)(get<0>(it->second) - get<2>(it->second)) * n - get<1>(it->second) + get<3>(it->second);
    }

    return distances;
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
    printArray(distance(nums));

    cout << endl;
}

int main() {
    test({1, 3, 1, 1, 2}, {5, 0, 3, 4, 0});
    test({0, 5, 3}, {0, 0, 0});
    test({2, 2, 2, 2}, {6, 4, 4, 6});
    test({1, 2, 1, 2, 1}, {6, 2, 4, 2, 6});
    test({7}, {0});

    return 0;
}
