#include <iostream>
#include <vector>

using namespace std;

int minDeletionSize(vector<string>& strs) {
    short m = strs[0].length();
    vector<short> length(m, 1);

    short j;
    short k;
    short n = strs.size() - 1;
    for(short i = 1; i < m; ++i) {
        for(j = i - 1; j > -1; --j) {
            for(k = n; k > -1; --k) {
                if(strs[k][i] < strs[k][j]) {
                    break;
                }
            }

            if(k < 0) {
                if(length[j] >= length[i]) {
                    length[i] = length[j] + 1;
                }
            }
        }
    }

    j = 0;
    for(k = m - 1; k > -1; --k) {
        if(length[k] > length[j]) {
            j = k;
        }
    }

    return m - length[j];
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
    test({"babca", "bbazb"}, 3);
    test({"edcba"}, 4);
    test({"ghi", "def", "abc"}, 0);
    test({"a", "b", "c"}, 0);
    test({"zyx", "wvu", "tsr"}, 2);

    return 0;
}
