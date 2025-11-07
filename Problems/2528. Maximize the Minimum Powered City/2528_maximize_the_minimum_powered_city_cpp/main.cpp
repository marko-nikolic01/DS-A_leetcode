#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool maxPower(vector<int>& arr, vector<long>& prefix, int r, long k, long mid, vector<long>& temp) {
    int n = arr.size();
    temp.assign(n, 0);
    long long extra = 0;
    int pre;
    int left;
    int right;
    long val;
    long req;
    int idx;

    for(int i = 0; i < n; ++i) {
        pre = (i > r) ? (i - r - 1) : -1;

        if(pre >= 0) {
            extra -= temp[pre];
        }

        left = max(0, i - r);
        right = min(n - 1, i + r);
        val = prefix[right] - (left > 0 ? prefix[left - 1] : 0);
        val += extra;

        if(val >= mid) {
            continue;
        }

        req = mid - val;

        if(req > k) {
            return false;
        }

        idx = min(i + r, n - 1);
        temp[idx] = req;
        extra += req;
        k -= req;
    }

    return true;
}

long long maxPower(vector<int>& stations, int r, int k) {
    int n = stations.size();
    vector<long> prefix(n);
    prefix[0] = stations[0];

    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + stations[i];
    }

    vector<long> temp;
    long low = 0;
    long high = accumulate(stations.begin(), stations.end(), 0LL) + k;
    long ans = 0;
    long mid;

    while(low <= high) {
        mid = low + (high - low) / 2LL;

        if(maxPower(stations, prefix, r, k, mid, temp)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> stations, int r, int k, long long expected) {
    cout << "Stations: ";
    printArray(stations);

    cout << "Range: " << r << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxPower(stations, r, k) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 4, 5, 0}, 1, 2, 5);
    test({4, 4, 4, 4}, 0, 3, 4);
    test({2, 1, 3}, 2, 3, 9);
    test({0, 0, 0, 0, 0}, 1, 10, 5);
    test({5, 0, 5, 0, 5}, 1, 0, 5);
    test({7}, 0, 5, 12);

    return 0;
}
