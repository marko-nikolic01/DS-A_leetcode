#include <iostream>
#include <vector>

using namespace std;

vector<int> numberOfLines(vector<int>& widths, string s) {
    int length = 0;
    int count = 0;

    int n = s.length();
    for(int i = 0; i < n; ++i) {
        if(length + widths[s[i] - 97] <= 100) {
            length += widths[s[i] - 97];
        } else {
            count++;
            length = widths[s[i] - 97];
        }
    }

    return {++count, length};
}

void runTest(vector<int> widths, string s, vector<int> expected) {
    cout << "Input: \"" << s << "\"" << endl;

    cout << "Widths: [ ";
    for (int w : widths) {
        cout << w << " ";
    }
    cout << "]" << endl;

    cout << "Expected: [ ";
    for (int e : expected) {
        cout << e << " ";
    }
    cout << "]" << endl;

    cout << "Result: [ ";
    for (int r : numberOfLines(widths, s)) {
        cout << r << " ";
    }
    cout << "]" << endl;

    cout << endl;

}

int main() {
    runTest({10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}, "abc", {1, 30});
    runTest({4, 2, 3, 1, 5, 6, 2, 7, 3, 8, 2, 5, 3, 4, 2, 4, 6, 7, 3, 2, 4, 6, 3, 2, 4, 1}, "zzz", {1, 3});
    runTest({5, 10, 3, 7, 8, 9, 2, 6, 4, 1, 6, 7, 5, 8, 9, 3, 7, 4, 5, 2, 6, 1, 8, 2, 7, 5}, "abcdefgh", {1, 50});
    runTest({1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, "aaaaaaaaaa", {1, 10});
    runTest({5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}, "abcdefgh", {1, 40});

    return 0;
}
