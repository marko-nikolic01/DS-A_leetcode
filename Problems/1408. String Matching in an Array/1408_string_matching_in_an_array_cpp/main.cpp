#include <iostream>
#include <vector>

using namespace std;

vector<string> stringMatching(vector<string>& words) {
    vector<string> result;
    for (short i = 0; i < words.size(); ++i) {
        for (short j = 0; j < words.size(); ++j) {
            if (i != j && words[j].find(words[i]) != string::npos) {
                result.push_back(words[i]);
                break;
            }
        }
    }
    return result;
}

void test(vector<string> words, vector<string> expected) {
    cout << "Words: ";
    for (string word : words) {
        cout << "\"" << word << "\" ";
    }
    cout << endl;

    cout << "Expected: ";
    for (string e : expected) {
        cout << "\"" << e << "\" ";
    }
    cout << endl;

    cout << "Result: ";
    for (string result : stringMatching(words)) {
        cout << "\"" << result << "\" ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    test({"mass", "as", "hero", "superhero"}, {"as", "hero"});
    test({"leetcode", "et", "code"}, {"et", "code"});
    test({"blue", "green", "bu"}, {});
    test({"abc", "bca", "cab", "ab"}, {"ab"});
    test({"xyz", "xy", "z", "x"}, {"xy", "z", "x"});

    return 0;
}
