#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    int ng = g.size();
    int ns = s.size();

    if(ns == 0) {
        return 0;
    }

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int count = 0;

    int i = 0;
    int j = 0;
    while(i < ng && j < ns) {
        if(g[i] <= s[j]) {
            count++;
            i++;
        }
        j++;
    }

    return count;
}

void runTest(vector<int> g, vector<int> s, int expected) {
    cout << "g: ";
    for (int i : g) cout << i << " ";
    cout << endl << "s: ";
    for (int i : s) cout << i << " ";
    int result = findContentChildren(g, s);
    cout << endl << "Expected: " << expected << endl;
    cout << "Result: " << result << endl << endl;
}

int main() {
    runTest({1, 2, 3}, {1, 1}, 1); // Only one child can be content
    runTest({1, 2}, {1, 2, 3}, 2); // Two children can be content
    runTest({1, 2, 3}, {3}, 1); // Only one child can be content
    runTest({1, 2, 3}, {0}, 0); // No child can be content
    runTest({1, 2, 3}, {}, 0); // No cookies, no child can be content

    return 0;
}
