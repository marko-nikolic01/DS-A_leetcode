#include <iostream>
#include <vector>

using namespace std;

vector<string> findWords(vector<string>& words) {
    vector<int> letterRow = {
        1, 2, 2, 1, 0, 1, 1, 1, 0, 1,
        1, 1, 2, 2, 0, 0, 0, 0, 1, 0,
        0, 2, 0, 2, 0, 2
    };

    vector<string> results;

    int n = words.size();
    for(int i = 0; i < n; ++i) {
        char letter = words[i][0];
        letter -= 65;
        if(letter > 25) {
            letter -= 32;
        }
        int currentRow = letterRow[letter];

        int l = words[i].length();
        for(int j = 0; j < l; ++j) {
            letter = words[i][j];
            letter -= 65;
            if(letter > 25) {
                letter -= 32;
            }

            if(currentRow != letterRow[letter]) {
                break;
            }

            if(j == l - 1) {
                results.push_back(words[i]);
            }
        }
    }

    return results;
}

void runTestCase(vector<string> words, vector<string> expected) {
    vector<string> result = findWords(words);

    cout << "Words: [";
    for (int i = 0; i < words.size(); ++i) {
        cout << words[i];
        if (i < words.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << "Expected: [";
    for (int i = 0; i < expected.size(); ++i) {
        cout << expected[i];
        if (i < expected.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << "Result: [";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << endl;
}

int main() {
    runTestCase({"Hello", "Alaska", "Dad", "Peace"}, {"Alaska", "Dad"});
    runTestCase({"Row", "Try", "Post"}, {"Row", "Try"});
    runTestCase({"Mop", "Xylophone", "Type"}, {"Type"});
    runTestCase({"Mom", "Pop", "Mop"}, {"Pop"});
    runTestCase({"Zebra", "Zoo", "Jig", "Piano"}, {});

    return 0;
}
