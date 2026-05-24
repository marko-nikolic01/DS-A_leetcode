#include <iostream>
#include <vector>

using namespace std;

class TrieNode {
private:
    vector<TrieNode*> nodes;
    bool isWord;

public:
    TrieNode() : isWord(false) {}

    void insert(string& word, short i) {
        if(--i < 0) {
            isWord = true;

            return;
        }

        short c = word[i] - '`';

        if(nodes.size() < c) {
            nodes.resize(c);
        }

        if(!nodes[--c]) {
            nodes[c] = new TrieNode();
        }

        nodes[c]->insert(word, i);
    }

    bool search(string& word, short i, bool canChange) {
        if(--i < 0) {
            return isWord && !canChange;
        }

        short c = word[i] - 'a';

        if(canChange) {
            for(short j = nodes.size() - 1; j > -1; --j) {
                if(j != c && nodes[j] && nodes[j]->search(word, i, false)) {
                    return true;
                }
            }
        }

        return nodes.size() > c && nodes[c] && nodes[c]->search(word, i, canChange);
    }
};

class Trie {
private:
    TrieNode* trie;

    void insert(string& word) {
        trie->insert(word, word.length());
    }

public:
    Trie() : trie(new TrieNode()) {}

    void insert(vector<string> dictionary) {
        for(short i = dictionary.size() - 1; i > -1; --i) {
            insert(dictionary[i]);
        }
    }

    bool search(string& word) {
        return trie->search(word, word.length(), true);
    }
};

class MagicDictionary {
private:
    Trie* trie;

public:
    MagicDictionary() : trie(new Trie()) {}

    void buildDict(vector<string> dictionary) {
        trie->insert(dictionary);
    }

    bool search(string searchWord) {
        return trie->search(searchWord);
    }
};

void printArray(vector<string> array) {
    for(string a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<string> commands, vector<vector<string>> inputs, vector<string> expected) {
    cout << "Commands: ";
    printArray(commands);

    cout << "Inputs: ";
    for(int i = 0; i < inputs.size(); ++i) {
        cout << "[";
        for(int j = 0; j < inputs[i].size(); ++j) {
            cout << "\"" << inputs[i][j] << "\"";
            if(j != inputs[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "] ";
    }
    cout << endl;

    MagicDictionary* magicDictionary;

    vector<string> results;
    for(int i = 0; i < commands.size(); i++) {
        if(commands[i] == "MagicDictionary") {
            magicDictionary = new MagicDictionary();
            results.push_back("null");
        } else if(commands[i] == "buildDict") {
            magicDictionary->buildDict(inputs[i]);
            results.push_back("null");
        } else if(commands[i] == "search") {
            results.push_back(magicDictionary->search(inputs[i][0]) ? "true" : "false");
        }
    }

    cout << "Expected: ";
    printArray(expected);

    cout << "Results: ";
    printArray(results);

    cout << endl;
}

int main() {
    test({"MagicDictionary", "buildDict", "search", "search", "search", "search"}, {{}, {"hello", "leetcode"}, {"hello"}, {"hhllo"}, {"hell"}, {"leetcoded"}}, {"null", "null", "false", "true", "false", "false"});
    test({"MagicDictionary", "buildDict", "search", "search"}, {{}, {"cat", "bat", "hat"}, {"cat"}, {"rat"}}, {"null", "null", "true", "true"});
    test({"MagicDictionary", "buildDict", "search", "search"}, {{}, {"abc"}, {"abc"}, {"adc"}}, {"null", "null", "false", "true"});
    test({"MagicDictionary", "buildDict", "search", "search"}, {{}, {"a"}, {"b"}, {"a"}}, {"null", "null", "true", "false"});
    test({"MagicDictionary", "buildDict", "search", "search"}, {{}, {"hello"}, {"hello"}, {"helo"}}, {"null", "null", "false", "false"});

    return 0;
}
