#include <iostream>
#include <vector>

using namespace std;

vector<int> validSequence(string word1, string word2) {
    vector<int> sequence;
    int n = word1.length();
    int m = word2.length();
    vector<int> last(m, -1);
    int skip = 0;

    int i;
    int j = m - 1;
    for(i = n - 1; i > -1; --i) {
        if(j > -1 && word1[i] == word2[j]) {
            last[j--] = i;
        }
    }

    j = 0;
    for(i = 0; i < n && j != m; ++i) {
        if(word1[i] == word2[j] || (skip == 0 && (j == m - 1 || i < last[j + 1]))) {
            skip += (word1[i] != word2[j++] ? 1 : 0);
            sequence.push_back(i);
        }
    }

    return j == m ? sequence : vector<int>();
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(string word1, string word2, vector<int> expected) {
    cout << "Word 1: " << "\"" << word1 << "\"" << endl;

    cout << "Word 2: " << "\"" << word2 << "\"" << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(validSequence(word1, word2));

    cout << endl;
}

int main() {
    test("vbcca", "abc", {0, 1, 2});
    test("bacdc", "abc", {1, 2, 4});
    test("aaaaaa", "aaabc", {});
    test("abc", "ab", {0, 1});
    test("xyz", "xyz", {0, 1, 2});

    return 0;
}
