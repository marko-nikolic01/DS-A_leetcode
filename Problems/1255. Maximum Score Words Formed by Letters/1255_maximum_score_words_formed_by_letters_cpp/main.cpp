#include <iostream>
#include <vector>

using namespace std;

void maxScoreWords(vector<string>& words, vector<short>& letters, vector<int>& score, short word, short currentScore, short& maxScore) {
    short nWords = words.size();
    for(short i = word + 1; i < nWords; ++i) {
        maxScoreWords(words, letters, score, i, currentScore, maxScore);
    }

    short n = words[word].size();
    for(short i = 0; i < n; ++i) {
        if(letters[words[word][i] - 'a'] == 0) {
            for(--i; i > -1; --i) {
                ++letters[words[word][i] - 'a'];
            }

            return;
        }

        --letters[words[word][i] - 'a'];
        currentScore += score[words[word][i] - 'a'];
    }

    if(currentScore > maxScore) {
        maxScore = currentScore;
    }

    for(short i = word + 1; i < nWords; ++i) {
        maxScoreWords(words, letters, score, i, currentScore, maxScore);
    }

    for(--n; n > -1; --n) {
        ++letters[words[word][n] - 'a'];
    }
}

int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
    vector<short> lettersOccurences(26, 0);
    for(short i = letters.size() - 1; i > -1; --i) {
        ++lettersOccurences[letters[i] - 'a'];
    }

    short maxScore = 0;

    maxScoreWords(words, lettersOccurences, score, 0, 0, maxScore);

    return maxScore;
}

void test(vector<string> words, vector<char> letters, vector<int> score, int expected) {
    cout << "Words: ";
    for(string word : words) {
        cout << "\"" << word << "\" ";
    }
    cout << endl;

    cout << "Letters: ";
    for(char letter : letters) {
        cout << "'" << letter << "' ";
    }
    cout << endl;

    cout << "Scores: ";
    for(int s : score) {
        cout << s << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxScoreWords(words, letters, score) << endl;

    cout << endl;
}

int main() {
    vector<string> words1 = {"dog", "cat", "dad", "good"};
    vector<char> letters1 = {'a', 'a', 'c', 'd', 'd', 'd', 'g', 'o', 'o'};
    vector<int> score1 = {1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int expected1 = 23;
    test(words1, letters1, score1, expected1);

    vector<string> words2 = {"xxxz", "ax", "bx", "cx"};
    vector<char> letters2 = {'z', 'a', 'b', 'c', 'x', 'x', 'x'};
    vector<int> score2 = {4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 10};
    int expected2 = 27;
    test(words2, letters2, score2, expected2);

    vector<string> words3 = {"leetcode"};
    vector<char> letters3 = {'l', 'e', 't', 'c', 'o', 'd'};
    vector<int> score3 = {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0};
    int expected3 = 0;
    test(words3, letters3, score3, expected3);

    vector<string> words4 = {"apple", "pear", "peach"};
    vector<char> letters4 = {'p', 'p', 'e', 'a', 'c', 'h'};
    vector<int> score4 = {1, 0, 0, 0, 2, 0, 3, 0, 1, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0};
    int expected4 = 3;
    test(words4, letters4, score4, expected4);

    vector<string> words5 = {"a", "aa", "aaa", "aaaa"};
    vector<char> letters5 = {'a', 'a', 'a', 'a'};
    vector<int> score5 = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int expected5 = 4;
    test(words5, letters5, score5, expected5);

    return 0;
}
