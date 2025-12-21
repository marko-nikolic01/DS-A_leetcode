#include <iostream>
#include <vector>

using namespace std;

int minDeletionSize(vector<string>& strs) {
    short deletions = 0;
    short n = strs.size();
    vector<bool> isPreviousSmaller(--n, false);
    short stringsLeft = n;
    bool isPreviousGreater;

    short j;
    short m = strs[0].length();
    for(short i = 0; i < m && stringsLeft > 0; ++i) {
        isPreviousGreater = false;

        for(j = 0; j < n; ++j) {
            if(!isPreviousSmaller[j] && strs[j][i] > strs[j + 1][i]) {
                isPreviousGreater = true;
                break;
            }
        }

        if(isPreviousGreater) {
            ++deletions;
            continue;
        }

        for(j = 0; j < n; ++j) {
            if(!isPreviousSmaller[j] && strs[j][i] < strs[j + 1][i]) {
                isPreviousSmaller[j] = true;
                --stringsLeft;
            }
        }
    }

    return deletions;
}

void printArray(vector<string> array) {
    for(string a : array) {
        cout << "\"" << a << "\"" << " ";
    }
    cout << endl;
}

void test(vector<string> strs, int expected) {
    cout << "Strings: ";
    printArray(strs);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minDeletionSize(strs) << endl;

    cout << endl;
}

int main() {
    test({ "ca", "bb", "ac" }, 1);
    test({ "xc", "yb", "za" }, 0);
    test({ "zyx", "wvu", "tsr" }, 3);
    test({ "aa", "aa", "aa" }, 0);
    test({ "ab", "aa", "ac" }, 1);

    return 0;
}
