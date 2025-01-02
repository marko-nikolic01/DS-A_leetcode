#include <iostream>
#include <vector>

using namespace std;

vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
    int n = words.size();
    vector<int> vowelStringCounts(n);

    if((words[0][0] == 'a' || words[0][0] == 'e' || words[0][0] == 'i' || words[0][0] == 'o' || words[0][0] == 'u') && (words[0].back() == 'a' || words[0].back() == 'e' || words[0].back() == 'i' || words[0].back() == 'o' || words[0].back() == 'u')) {
        vowelStringCounts[0] = 1;
        words[0][0] = 'A';
    } else {
        vowelStringCounts[0] = 0;
    }

    for(int i = 1; i < n; ++i) {
        vowelStringCounts[i] = vowelStringCounts[i - 1];

        if((words[i][0] == 'a' || words[i][0] == 'e' || words[i][0] == 'i' || words[i][0] == 'o' || words[i][0] == 'u') && (words[i].back() == 'a' || words[i].back() == 'e' || words[i].back() == 'i' || words[i].back() == 'o' || words[i].back() == 'u')) {
            ++vowelStringCounts[i];
            words[i][0] = 'A';
        }
    }

    n = queries.size();
    vector<int> result(n);

    for(--n; n > -1; --n) {
        result[n] = vowelStringCounts[queries[n][1]] - vowelStringCounts[queries[n][0]];
        if(words[queries[n][0]][0] == 'A') {
            ++result[n];
        }
    }

    return result;
}

void test(vector<string> words, vector<vector<int>> queries, vector<int> expected) {
    cout << "Words: ";
    for (string word : words) {
        cout << "\"" << word << "\" ";
    }
    cout << endl;

    cout << "Queries: ";
    for (vector<int> query : queries) {
        cout << "[" << query[0] << " " << query[1] << "] ";
    }
    cout << endl;

    cout << "Expected: ";
    for (int e : expected) {
        cout << e << " ";
    }
    cout << endl;

    cout << "Result: ";
    for (int result : vowelStrings(words, queries)) {
        cout << result << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    test({"aba", "bcb", "ece", "aa", "e"}, {{0, 2}, {1, 4}, {1, 1}}, {2, 3, 0});
    test({"a", "e", "i"}, {{0, 2}, {0, 1}, {2, 2}}, {3, 2, 1});
    test({"apple", "banana", "orange", "grape", "elephant"}, {{0, 2}, {1, 4}, {0, 4}}, {2, 1, 2});
    test({"cat", "dog", "egg", "ice", "ace"}, {{0, 1}, {2, 4}, {1, 3}}, {0, 2, 1});
    test({"echo", "output", "input", "extra"}, {{0, 3}, {1, 2}}, {2, 0});
    test({"aei", "iou", "ae", "oi", "ea"}, {{0, 4}, {1, 3}, {0, 2}}, {5, 3, 3});
    test({"bat", "kit", "eat", "sit", "on"}, {{0, 1}, {2, 4}, {1, 3}}, {0, 0, 0});

    return 0;
}
