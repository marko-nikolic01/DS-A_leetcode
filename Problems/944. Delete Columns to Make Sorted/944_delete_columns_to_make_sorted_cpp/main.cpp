#include <iostream>
#include <vector>

using namespace std;

int minDeletionSize(vector<string>& strs) {
    short deletions = 0;

    short i;
    short n = strs.size() - 1;
    for(short j = strs[0].size() - 1; j > -1; --j) {
        for(i = n; i > 0; --i) {
            if(strs[i - 1][j] > strs[i][j]) {
                break;
            }
        }

        if(i > 0) {
            ++deletions;
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
    test({"cba", "daf", "ghi"}, 1);
    test({"a", "b"}, 0);
    test({"zyx", "wvu", "tsr"}, 3);
    test({"abc", "bce", "cae"}, 1);
    test({"aa", "aa", "aa"}, 0);

    return 0;
}
