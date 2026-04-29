#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string arrangeWords(string text) {
    int n = text.length();
    string arrangedWords(n, ' ');
    vector<pair<int, int>> words;

    text[0] += 32;

    int i;
    for(i = 0; i < n; ++i) {
        words.push_back({1, i});

        while(++i < n && text[i] != ' ') {
            ++words.back().first;
        }
    }

    sort(words.begin(), words.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        return a.first > b.first || (a.first == b.first && a.second > b.second);
    });

    int j = -2;
    for(i = words.size() - 1; i > -1; --i) {
        ++j;
        while(words[i].second < n && text[words[i].second] != ' ') {
            arrangedWords[++j] = text[words[i].second++];
        }
    }

    arrangedWords[0] -= 32;

    return arrangedWords;
}

void test(string text, string expected) {
    cout << "Text: " << "\"" << text << "\"" << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << arrangeWords(text) << "\"" << endl;

    cout << endl;
}

int main() {
    test("Leetcode is cool", "Is cool leetcode");
    test("Keep calm and code on", "On and keep calm code");
    test("To be or not to be", "To be or to be not");
    test("Hello", "Hello");
    test("Tri bi ai", "Bi ai tri");

    return 0;
}
