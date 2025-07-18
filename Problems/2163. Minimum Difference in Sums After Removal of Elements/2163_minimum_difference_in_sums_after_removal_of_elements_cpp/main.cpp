#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long minimumDifference(vector<int>& nums) {
    int n3 = nums.size(), n = n3 / 3;
    vector<long> part1(n + 1);
    long sum = 0;
    priority_queue<int> ql;

    int i;
    for(i = 0; i < n; ++i) {
        sum += nums[i];
        ql.push(nums[i]);
    }

    part1[0] = sum;

    for(i = n; i < n * 2; ++i) {
        sum += nums[i];
        ql.push(nums[i]);
        sum -= ql.top();
        ql.pop();
        part1[i - (n - 1)] = sum;
    }

    long part2 = 0;
    priority_queue<int, vector<int>, greater<int>> qr;

    for( i = n * 3 - 1; i >= n * 2; --i) {
        part2 += nums[i];
        qr.push(nums[i]);
    }

    long ans = part1[n] - part2;

    for(i = n * 2 - 1; i >= n; --i) {
        part2 += nums[i];
        qr.push(nums[i]);
        part2 -= qr.top();
        qr.pop();
        ans = min(ans, part1[i - n] - part2);
    }

    return ans;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, long long expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minimumDifference(nums) << endl;

    cout << endl;
}


int main() {
    test({3, 1, 2}, -1);
    test({7, 9, 5, 8, 1, 3}, 1);
    test({1, 2, 3, 4, 5, 6}, -8);
    test({100000, 100000, 100000, 1, 1, 1}, 99999);
    test({10, 20, 30, 5, 5, 5}, -5);

    return 0;
}
