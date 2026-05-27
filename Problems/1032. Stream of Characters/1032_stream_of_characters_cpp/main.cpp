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

        bool search(string& query, short i) {
            if(isWord) {
                return true;
            } else if(--i < 0) {
                return false;
            }

            short c = query[i] - 'a';

            return nodes.size() > c && nodes[c] ? nodes[c]->search(query, i) : false;
        }
};

class Trie {
    private:
        TrieNode* trie;

    public:
        Trie() : trie(new TrieNode()) {}

        void insert(string& word) {
            trie->insert(word, word.length());
        }

        bool search(string& query) {
            return trie->search(query, query.length());
        }
};

class StreamChecker {
    private:
        string stream;
        Trie* trie;

    public:
        StreamChecker(vector<string>& words) : stream(""), trie(new Trie()) {
            for(short i = words.size() - 1; i > -1; --i) {
                trie->insert(words[i]);
            }
        }

        bool query(char letter) {
            stream.push_back(letter);

            return trie->search(stream);
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

    StreamChecker* streamChecker;

    vector<string> results;
    for(int i = 0; i < commands.size(); i++) {
        if(commands[i] == "StreamChecker") {
            streamChecker = new StreamChecker(inputs[i]);
            results.push_back("null");
        } else if(commands[i] == "query") {
            results.push_back(streamChecker->query(inputs[i][0][0]) ? "true" : "false");
        }
    }

    cout << "Expected: ";
    printArray(expected);

    cout << "Results: ";
    printArray(results);

    cout << endl;
}

int main() {
    test({"StreamChecker", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query"}, {{{"cd", "f", "kl"}}, {"a"}, {"b"}, {"c"}, {"d"}, {"e"}, {"f"}, {"g"}, {"h"}, {"i"}, {"j"}, {"k"}, {"l"}}, {"null", "false", "false", "false", "true", "false", "true", "false", "false", "false", "false", "false", "true"});
    test({"StreamChecker", "query", "query", "query"}, {{{"z"}}, {"a"}, {"b"}, {"z"}}, {"null", "false", "false", "true"});
    test({"StreamChecker", "query", "query", "query"}, {{{"xy"}}, {"a"}, {"b"}, {"c"}}, {"null", "false", "false", "false"});
    test({"StreamChecker", "query"}, {{{"a"}}, {"a"}}, {"null", "true"});
    test({"StreamChecker", "query", "query", "query", "query"}, {{{"ab"}}, {"x"}, {"y"}, {"a"}, {"b"}}, {"null", "false", "false", "false", "true"});

    return 0;
}
