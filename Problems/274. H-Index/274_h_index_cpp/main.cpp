#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end());

    int hIndex = 0;

    int n = citations.size();
    for(int i = 0; hIndex < n - i; ++i) {
        hIndex = max(hIndex, min(citations[i], n - i));
    }

    return hIndex;
}

void runTestCase(vector<int> citations, int expected) {
    cout << "Citations: [";
    for (size_t i = 0; i < citations.size(); ++i) {
        cout << citations[i];
        if (i != citations.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << hIndex(citations) << endl;

    cout << endl;
}

int main() {
    runTestCase({3, 0, 6, 1, 5}, 3);
    runTestCase({1, 2, 3, 4, 5}, 3);
    runTestCase({0, 0, 0, 0}, 0);
    runTestCase({5, 5, 5, 5}, 4);
    runTestCase({10, 8, 5, 4, 3}, 4);
    runTestCase({}, 0);
    runTestCase({1, 2, 3}, 2);

    return 0;
}
