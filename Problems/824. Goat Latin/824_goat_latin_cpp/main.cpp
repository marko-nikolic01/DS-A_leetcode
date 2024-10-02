#include <iostream>
#include <unordered_set>

using namespace std;

string toGoatLatin(string sentence) {
    unordered_set<char> vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};

    string goatSentence = "";

    string a = "a";

    int n = sentence.length();
    for(int i = 0 ; i < n; ++i) {
        int start;

        if(vowels.find(sentence[i]) != vowels.end()) {
            start = -1;
            goatSentence += sentence[i];
        } else {
            start = i;
        }

        while(++i < n && sentence[i] != ' ') {
            goatSentence += sentence[i];
        }

        while(i < n && sentence[i] == ' ') {
            i++;
        }

        if(start > -1) {
            goatSentence += sentence[start];
        }
        goatSentence += "ma" + a;
        if(i < n) {
            goatSentence += ' ';
            a += 'a';
        }

        i--;
    }

    return goatSentence;
}

void testToGoatLatin(const string& sentence, const string& expected) {
    cout << "Sentence: \"" << sentence << "\"" << endl;

    cout << "Expected: \"" << expected << "\"" << endl;

    cout << "Result: \"" << toGoatLatin(sentence) << "\"" << endl;

    cout << endl;
}

int main() {
    testToGoatLatin("I speak Goat Latin", "Imaa peaksmaaa oatGmaaaa atinLmaaaaa");
    testToGoatLatin("The quick brown fox jumped over the lazy dog", "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa");

    return 0;
}
