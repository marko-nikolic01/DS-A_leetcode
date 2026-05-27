#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class TrieNode {
    private:
        vector<TrieNode*> nodes;
        vector<short> words;

    public:
        TrieNode() {}

        void insert(string& word, short index, short i, short operation) {
            words.push_back(index);

            i += operation;
            if((operation < 0 && i < 0) || (operation > 0 && i == word.length())) {
                return;
            }

            short c = word[i] - '`';

            if(nodes.size() < c) {
                nodes.resize(c);
            }

            if(!nodes[--c]) {
                nodes[c] = new TrieNode();
            }

            nodes[c]->insert(word, index, i, operation);
        }

        short search(string& preffixSuffix, unordered_set<short>& searchResults, short i, short operation) {
            i += operation;
            if((operation < 0 && i < 0) || (operation > 0 && i == preffixSuffix.length())) {
                if(searchResults.empty()) {
                    for(i = words.size() - 1; i > -1; --i) {
                        searchResults.insert(words[i]);
                    }

                    return -1;
                }

                operation = -1;
                for(i = words.size() - 1; i > -1; --i) {
                    if(searchResults.find(words[i]) != searchResults.end() && words[i] > operation) {
                        operation = words[i];
                    }
                }

                return operation;
            }

            short c = preffixSuffix[i] - 'a';

            return nodes.size() > c && nodes[c] ? nodes[c]->search(preffixSuffix, searchResults, i, operation) : -1;

        }
};

class Trie {
    private:
        TrieNode* prefixTrie;
        TrieNode* suffixTrie;
        unordered_set<string> uniqueWords;
        unordered_map<string, unordered_map<string, short>> searchResults;
        unordered_set<short> searchResult;

        void insert(string& word, short index) {
            if(uniqueWords.find(word) == uniqueWords.end()) {
                prefixTrie->insert(word, index, -1, 1);
                suffixTrie->insert(word, index, word.length(), -1);
            }
        }

    public:
        Trie() : prefixTrie(new TrieNode()), suffixTrie(new TrieNode()) {}

        void insert(vector<string>& words) {
            for(short i = words.size() - 1; i > -1; --i) {
                insert(words[i], i);
            }
        }

        short search(string& prefix, string& suffix) {
            if(searchResults.find(prefix) == searchResults.end() || searchResults[prefix].find(suffix) == searchResults[prefix].end()) {
                searchResult.clear();
                prefixTrie->search(prefix, searchResult, -1, 1);
                searchResults[prefix][suffix] = suffixTrie->search(suffix, searchResult, suffix.length(), -1);
            }

            return searchResults[prefix][suffix];
        }
};

class WordFilter {
    private:
        Trie* trie;

    public:
        WordFilter(vector<string>& words) : trie(new Trie()) {
            trie->insert(words);
        }

        int f(string pref, string suff) {
            return trie->search(pref, suff);
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

    WordFilter* wordFilter;

    vector<string> results;
    for(int i = 0; i < commands.size(); i++) {
        if(commands[i] == "WordFilter") {
            wordFilter = new WordFilter(inputs[i]);
            results.push_back("null");
        } else if(commands[i] == "f") {
            results.push_back(to_string(wordFilter->f(inputs[i][0], inputs[i][1])));
        }
    }

    cout << "Expected: ";
    printArray(expected);

    cout << "Results: ";
    printArray(results);

    cout << endl;
}

int main() {
    test({"WordFilter", "f"}, {{"apple"}, {"a", "e"}}, {"null", "0"});
    test({"WordFilter", "f"}, {{"apple"}, {"b", "e"}}, {"null", "-1"});
    test({"WordFilter", "f", "f"}, {{"apple", "maple"}, {"a", "le"}, {"m", "le"}}, {"null", "0", "1"});
    test({"WordFilter", "f"}, {{"apple", "apple"}, {"a", "e"}}, {"null", "1"});
    test({"WordFilter", "f"}, {{"ab"}, {"ab", "ab"}}, {"null", "0"});

    return 0;
}
