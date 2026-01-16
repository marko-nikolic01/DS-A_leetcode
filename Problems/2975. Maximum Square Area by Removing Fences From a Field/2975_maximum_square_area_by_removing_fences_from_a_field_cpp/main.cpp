#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
    unordered_set<int> fences;
    long length = -1;

    hFences.push_back(1);
    hFences.push_back(m);
    vFences.push_back(1);
    vFences.push_back(n);
    sort(hFences.begin(), hFences.end());
    sort(vFences.begin(), vFences.end());

    short i;
    n = hFences.size();
    for(i = 0; i < n; ++i){
        for(m = i + 1; m < n; ++m){
            fences.insert(hFences[m] - hFences[i]);
        }
    }


    n = vFences.size();
    for(i = 0; i < n; ++i){
        for(m = i + 1; m < n; ++m){
            if(fences.count(vFences[m] - vFences[i]))
                length = max(length, (long)vFences[m] - vFences[i]);
        }
    }

    return length < 0 ? length : length * length % 1000000007;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(int n, int m, vector<int> hFences, vector<int> vFences, int expected) {
    cout << "n: " << n << endl;

    cout << "m: " << m << endl;

    cout << "Horizontal fences: ";
    printArray(hFences);

    cout << "Vertical fences: ";
    printArray(vFences);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maximizeSquareArea(n, m, hFences, vFences) << endl;

    cout << endl;
}

int main() {
    test(4, 3, {2, 3}, {2}, 4);
    test(6, 7, {2}, {4}, -1);
    test(5, 5, {2, 3, 4}, {2, 3, 4}, 16);
    test(8, 6, {3, 5}, {2, 4}, 25);
    test(10, 12, {3, 6, 9}, {4, 8}, 64);

    return 0;
}
