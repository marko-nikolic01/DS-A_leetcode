#include <iostream>
#include <vector>

using namespace std;

string findTheString(vector<vector<int>>& lcp) {
    short n = lcp.size();
    string word(n, '\0');
    char current = 'a';

    short i;
    short j;
    for(i = 0; i < n; ++i) {
        if(word[i] == '\0') {
            if(current > 'z') {
                return "";
            }

            word[i] = current;

            for(j = i + 1; j < n; ++j) {
                if(lcp[i][j] > 0) {
                    word[j] = word[i];
                }
            }

            ++current;
        }
    }

    for(i = --n; i > -1; --i) {
        for(j = n; j > -1; --j) {
            if(word[i] != word[j]) {
                if (lcp[i][j]) {
                    return "";
                }
            } else if(i == n || j == n) {
                if(lcp[i][j] != 1) {
                    return "";
                }
            } else if(lcp[i][j] != lcp[i + 1][j + 1] + 1) {
                return "";
            }
        }
    }

    return word;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> lcp, string expected) {
    cout << "Longest common prefixes:" << endl;
    printMatrix(lcp);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << findTheString(lcp) << endl;

    cout << endl;
}

int main() {
    test({{4, 0, 2, 0}, {0, 3, 0, 1}, {2, 0, 2, 0}, {0, 1, 0, 1}}, "abab");
    test({{4, 3, 2, 1}, {3, 3, 2, 1}, {2, 2, 2, 1}, {1, 1, 1, 1}}, "aaaa");
    test({{4, 3, 2, 1}, {3, 3, 2, 1}, {2, 2, 2, 1}, {1, 1, 1, 3}}, "");
    test({{3, 0, 0}, {0, 3, 0}, {0, 0, 3}}, "");
    test({{2, 1}, {1, 2}}, "");

    return 0;
}
