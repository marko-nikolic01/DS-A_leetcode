#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string shortestCompletingWord(string licensePlate, vector<string>& words) {
    unordered_map<char, int> letters;

    int n = licensePlate.length() - 1;
    for(n; n > -1; --n) {
        if(licensePlate[n] >= 65 && licensePlate[n] <= 90) {
            licensePlate[n] += 32;
        }

        if(licensePlate[n] >= 97 && licensePlate[n] <= 122) {
            if(letters.find(licensePlate[n]) == letters.end()) {
                letters[licensePlate[n]] = 1;
            } else {
                letters[licensePlate[n]]++;
            }
        }
    }

    string completingWord = "";

    n = words.size();
    for(int i = 0; i < n; ++i) {
        if(completingWord.length() == 0 || words[i].length() < completingWord.length()) {
            unordered_map<char, int> wordLetters = letters;

            for(int j = words[i].length() - 1; j > -1; --j) {
                if(wordLetters.find(words[i][j]) != wordLetters.end()) {
                    if(wordLetters[words[i][j]] == 1) {
                        wordLetters.erase(words[i][j]);
                    } else {
                        wordLetters[words[i][j]]--;
                    }
                }
            }

            if(wordLetters.empty()) {
                completingWord = words[i];
            }
        }
    }

    return completingWord;
}

void runTest(string licensePlate, vector<string> words, string expected) {
    cout << "License plate: " << licensePlate << endl;

    cout << "Words: ";
    for (const string& word : words) {
        cout << word << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << shortestCompletingWord(licensePlate, words) << endl;

    cout << endl;
}

int main() {
    runTest("1s3 PSt", {"step", "steps", "stripe", "stepple"}, "steps");
    runTest("1s3 456", {"looks", "pest", "stew", "show"}, "pest");
    runTest("Ah71752", {"java", "hastle", "ham", "react"}, "ham");
    runTest("Og7v3m", {"omega", "moving", "vogue"}, "moving");
    runTest("Pq99", {"quick", "queue", "plaque"}, "plaque");

    return 0;
}
