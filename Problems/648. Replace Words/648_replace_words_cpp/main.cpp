#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

string replaceWords(vector<string>& dictionary, string sentence) {
    unordered_set<string> roots;
    string word;

    sentence.push_back(' ');

    int i;
    for(i = dictionary.size() - 1; i > -1; --i) {
        roots.insert(dictionary[i]);
    }

    int iSentence = -1;
    int n = sentence.length();
    for(i = 0; i < n; ++i) {
        word.resize(0);

        while(i < n && sentence[i] > ' ' && roots.find(word) == roots.end()) {
            sentence[++iSentence] = sentence[i];
            word.push_back(sentence[i++]);
        }

        if(roots.find(word) != roots.end()) {
            while(sentence[i] > ' ') {
                ++i;
            }
        }

        sentence[++iSentence] = ' ';
    }

    sentence.resize(iSentence);

    return sentence;
}

void printArray(vector<string> array) {
    for(string a : array) {
        cout << "\"" << a << "\"" << " ";
    }
    cout << endl;
}

void test(vector<string> dictionary, string sentence, string expected) {
    cout << "Dictionary: ";
    printArray(dictionary);

    cout << "Sentence: " << "\"" << sentence << "\"" << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << replaceWords(dictionary, sentence) << "\"" << endl;

    cout << endl;
}

int main() {
    test({"cat", "bat", "rat"}, "the cattle was rattled by the battery", "the cat was rat by the bat");
    test({"a", "b", "c"}, "aadsfasf absbs bbab cadsfafs", "a a b c");
    test({"blue", "blu", "b"}, "blueberry black blue", "b b b");
    test({"hello"}, "hello hellohello hell", "hello hello hell");
    test({"x", "xy", "xyz"}, "xyz xy x xylophone", "x x x x");

    return 0;
}
