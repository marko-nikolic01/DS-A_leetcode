#include <iostream>
#include <vector>

using namespace std;

long long minCost(string s, vector<int>& cost) {
    vector<long> costs(26, 0);
    long totalCost = 0;
    short maximumCost = 0;

    int i;
    for(i = s.length() - 1; i > -1; --i) {
        costs[s[i] - 'a'] += cost[i];
        totalCost += cost[i];
    }

    for(i = 1; i < 26; ++i) {
        if(costs[i] > 0 && costs[i] > costs[maximumCost]) {
            maximumCost = i;
        }
    }

    return totalCost - costs[maximumCost];
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(string s, vector<int> cost, long long expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Costs: ";
    printArray(cost);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minCost(s, cost) << endl;

    cout << endl;
}

int main() {
    test("aabaac", {1, 2, 3, 4, 1, 10}, 11);
    test("abc", {10, 5, 8}, 13);
    test("zzzzz", {67, 67, 67, 67, 67}, 0);
    test("bbbbac", {5, 4, 3, 2, 10, 1}, 11);
    test("caaab", {1, 100, 1, 1, 50}, 51);
    test("a", {1}, 0);

    return 0;
}
