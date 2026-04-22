#include <iostream>
#include <vector>

using namespace std;

class TrieNode {
    private:
        vector<TrieNode*> nodes;

    public:
        TrieNode() : nodes(26, nullptr) {}

        void add(string& word, short i) {
            if(i < word.length()) {
                short c = word[i] - 'a';

                if(!nodes[c]) {
                    nodes[c] = new TrieNode();
                }

                nodes[c]->add(word, ++i);
            }
        }

        bool search(string& word, short edits, short i) {
            if(i == word.size()) {
                return true;
            }

            short c = word[i++] - 'a';

            if(nodes[c] && nodes[c]->search(word, edits, i)) {
                return true;
            } else if(--edits > -1) {
                for(short j = 0; j < 26; ++j) {
                    if(j != c && nodes[j] && nodes[j]->search(word, edits, i)) {
                        return true;
                    }
                }
            }

            return false;
        }
};

class Trie {
    private:
        TrieNode* trie;

    public:
        Trie() : trie(new TrieNode()) {}

        void add(string& word) {
            trie->add(word, 0);
        }

        bool search(string& word) {
            return trie->search(word, 2, 0);
        }
};

vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
    Trie* trie = new Trie();

    short i;
    for(i = dictionary.size() - 1; i > -1; --i) {
        trie->add(dictionary[i]);
    }

    short iResult = -1;
    short iWord;
    short n = queries.size();
    short nWord = queries[0].length() - 1;
    while(++i < n) {
        if(trie->search(queries[i])) {
            ++iResult;
            for(iWord = nWord; iWord > -1; --iWord) {
                queries[iResult][iWord] = queries[i][iWord];
            }
        }
    }

    queries.resize(++iResult);

    return queries;
}

void printArray(vector<string> array) {
    for(string a : array) {
        cout << "\"" << a << "\"" << " ";
    }
    cout << endl;
}

void test(vector<string> queries, vector<string> dictionary, vector<string> expected) {
    cout << "Queries: ";
    printArray(queries);

    cout << "Dictionary: ";
    printArray(dictionary);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(twoEditWords(queries, dictionary));

    cout << endl;
}

int main() {
    test({"word", "note", "ants", "wood"}, {"wood", "joke", "moat"}, {"word", "note", "wood"});
    test({"yes"}, {"not"}, {});
    test({"prfturjd", "iarapqqk", "aokbrtmx", "yafmjorj", "larakqqk", "nliynmpm", "isikkcws", "laraeqqk"}, {"apahhijt", "larapqqk", "isukkcws", "siqqoacj", "nloynmpm"}, {"iarapqqk", "larakqqk", "nliynmpm", "isikkcws", "laraeqqk"});
    test({"abc"}, {"abc"}, {"abc"});
    test({"abc", "xyz"}, {"abc", "aaa"}, {"abc"});
    test({"kitten", "mitten", "bitten"}, {"litten", "written", "sitting"}, {"kitten", "mitten", "bitten"});
    return 0;
}
