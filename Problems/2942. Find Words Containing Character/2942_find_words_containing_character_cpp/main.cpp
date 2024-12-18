#include <iostream>
#include <vector>

using namespace std;

vector<int> findWordsContaining(vector<string>& words, char x) {
    vector<int> result;

    for(int i = words.size() - 1; i > -1; --i) {
        for(int j = words[i].length() - 1; j > -1; --j) {
            if(words[i][j] == x) {
                result.push_back(i);
                break;
            }
        }
    }

    return result;
}

void test(vector<string> words, char x, vector<int> expected) {
    cout << "Words: ";
    for (string word : words) {
        cout << "\"" << word << "\" ";
    }
    cout << endl;

    cout << "x: '" << x << "'" << endl;

    cout << "Expected: ";
    for (int e : expected) {
        cout << e << " ";
    }
    cout << endl;

    cout << "Result: ";
    for (int result : findWordsContaining(words, x)) {
        cout << result << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    test({"apple", "banana", "cherry"}, 'a', {1, 0});
    test({"dog", "cat", "fish", "elephant"}, 'e', {3});
    test({"hello", "world", "cpp", "programming"}, 'p', {3, 2});
    test({"test", "case", "function", "example"}, 'z', {});
    test({"alpha", "beta", "gamma", "delta"}, 'a', {3, 2, 1, 0});
    test({"xray", "yankee", "zulu"}, 'y', {1, 0});
    test({"aaa"}, 'a', {0});
    test({"bcd"}, 'a', {});
    test({"singleword"}, 's', {0});

    return 0;
}
