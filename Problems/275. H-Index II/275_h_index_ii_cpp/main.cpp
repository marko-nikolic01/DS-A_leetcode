#include <iostream>
#include <vector>

using namespace std;

int hIndex(vector<int>& citations) {
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
    runTestCase({0}, 0);
    runTestCase({1}, 1);
    runTestCase({1, 2}, 1);
    runTestCase({1, 2, 3}, 2);
    runTestCase({1, 2, 3, 4}, 2);
    runTestCase({1, 2, 3, 4, 5}, 3);
    runTestCase({1, 2, 3, 4, 5, 6}, 3);
    runTestCase({3, 4, 5, 6, 7}, 4);
    runTestCase({4, 4, 4, 4}, 4);
    runTestCase({5, 6, 7, 8, 9}, 5);

    return 0;
}
