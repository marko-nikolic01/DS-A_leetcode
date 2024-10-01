#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

string mostCommonWord(string paragraph, vector<string>& banned) {
    unordered_set<string> bannedWords;
    for(int i = banned.size() - 1; i > -1; --i) {
        bannedWords.insert(banned[i]);
    }

    unordered_map<string, int> words;
    int max = 0;
    string maxWord = "";
    string word = "";

    int n = paragraph.length();
    for(int i = 0; i < n; ++i) {
        if(paragraph[i] > 96 && paragraph[i] < 123) {
            word += paragraph[i];
        } else if(paragraph[i] > 64 && paragraph[i] < 91) {
            word += paragraph[i] + 32;
        } else if(word.length() > 0) {
            if(bannedWords.find(word) == bannedWords.end()) {
                if(words.find(word) == words.end()) {
                    words[word] = 1;
                } else {
                    words[word]++;
                }

                if(words[word] > max) {
                    max = words[word];
                    maxWord = word;
                }
            }

            word = "";
        }
    }

    if(word.length() > 0) {
        if(bannedWords.find(word) == bannedWords.end()) {
            if(words.find(word) == words.end()) {
                words[word] = 1;
            } else {
                words[word]++;
            }

            if(words[word] > max) {
                max = words[word];
                maxWord = word;
            }
        }
    }

    return maxWord;
}

void testMostCommonWord(const string& paragraph, vector<string>& banned, const string& expected) {
    cout << "Paragraph: " << paragraph << endl;

    cout << "Banned words: ";
    for (const string& word : banned) cout << word << " ";
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << mostCommonWord(paragraph, banned) << endl;

    cout << endl;
}

int main() {
    string paragraph1 = "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> banned1 = {"hit"};
    string expected1 = "ball";
    testMostCommonWord(paragraph1, banned1, expected1);

    string paragraph2 = "It is a truth universally acknowledged, that a single man in possession of a good fortune, must be in want of a wife.";
    vector<string> banned2 = {"a"};
    string expected2 = "in";
    testMostCommonWord(paragraph2, banned2, expected2);

    string paragraph3 = "Jack and Jill went up the hill to fetch a pail of water. Jack fell down and broke his crown, and Jill came tumbling after.";
    vector<string> banned3 = {"and", "a", "the"};
    string expected3 = "jack";
    testMostCommonWord(paragraph3, banned3, expected3);

    string paragraph4 = "a, a, a, a, b,b,b,c, c";
    vector<string> banned4 = {"a"};
    string expected4 = "b";
    testMostCommonWord(paragraph4, banned4, expected4);

    string paragraph5 = "a";
    vector<string> banned5 = {""};
    string expected5 = "a";
    testMostCommonWord(paragraph5, banned5, expected5);

    string paragraph6 = " .!,a ";
    vector<string> banned6 = {""};
    string expected6 = "a";
    testMostCommonWord(paragraph6, banned6, expected6);

    return 0;
}
