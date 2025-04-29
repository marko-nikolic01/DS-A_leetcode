#include <iostream>
#include <vector>

using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> text;
    short lines = -1;
    short firstWord;
    short wordsLength;
    short spaces;
    short additionalSpaces;

    short j;
    short k;
    short l;
    short n = words.size();
    for(short i = 0; i < n; ++i) {
        text.push_back("");
        ++lines;

        firstWord = i;
        wordsLength = words[i].length();
        spaces = 0;

        while(++i < n && wordsLength + words[i].length() + spaces + 1 <= maxWidth) {
            wordsLength += words[i].length();
            ++spaces;
        }

        if(i == n) {
            for(firstWord; firstWord < n; ++firstWord) {
                k = words[firstWord].length();
                for(j = 0; j < k; ++j) {
                    text[lines].push_back(words[firstWord][j]);
                }

                text[lines].push_back(' ');
            }
            text[lines].pop_back();

            for(j = maxWidth - wordsLength - spaces; j > 0; --j) {
                text[lines].push_back(' ');
            }
        } else {
            j = --i - firstWord;

            if(j < 1) {
                additionalSpaces = maxWidth - wordsLength;
            } else {
                spaces += maxWidth - wordsLength - spaces;
                additionalSpaces = spaces % j;
                spaces = spaces / j;
            }

            for(firstWord; firstWord < i; ++firstWord) {
                k = words[firstWord].length();
                for(j = 0; j < k; ++j) {
                    text[lines].push_back(words[firstWord][j]);
                }

                for(j = spaces; j > 0; --j) {
                    text[lines].push_back(' ');
                }

                if(additionalSpaces > 0) {
                    text[lines].push_back(' ');
                    --additionalSpaces;
                }
            }

            k = words[i].length();
            for(j = 0; j < k; ++j) {
                text[lines].push_back(words[i][j]);
            }

            while(additionalSpaces-- > 0) {
                text[lines].push_back(' ');
            }
        }
    }

    return text;
}

void printArray(vector<string> array) {
    for(string a : array) {
        cout << "\"" <<  a << "\"" << " ";
    }
    cout << endl;
}

void test(vector<string> words, int maxWidth, vector<string> expected) {
    cout << "Words: ";
    printArray(words);

    cout << "Maximum width: " << maxWidth << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(fullJustify(words, maxWidth));

    cout << endl;
}

int main() {
    test({"This", "is", "an", "example", "of", "text", "justification."}, 16, {"This    is    an", "example  of text", "justification.  "});
    test({"What","must","be","acknowledgment","shall","be"}, 16, {"What   must   be", "acknowledgment  ", "shall be        "});
    test({"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"}, 20, {"Science  is  what we", "understand      well", "enough to explain to", "a  computer.  Art is", "everything  else  we", "do                  "});
    test({"hello"}, 10, {"hello     "});
    test({"a", "b", "c", "d", "e"}, 9, {"a b c d e"});

    return 0;
}
