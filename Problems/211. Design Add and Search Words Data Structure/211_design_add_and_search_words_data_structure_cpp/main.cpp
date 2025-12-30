#include <iostream>
#include <vector>

using namespace std;

class WordDictionary {
    private:
        vector<WordDictionary*> nodes;
        bool isWord;

    public:
        WordDictionary() : nodes(26, nullptr) {
            isWord = false;
        }

        void addWord(string& word, short i) {
            if(i == word.length()) {
                isWord = true;
                return;
            }

            word[i] -= 'a';

            if(!nodes[word[i]]) {
                nodes[word[i]] = new WordDictionary();
            }

            nodes[word[i]]->addWord(word, ++i);
        }

        void addWord(string word) {
            addWord(word, 0);
        }

        bool search(string& word, short i) {
            if(i == word.size()) {
                return isWord;
            } else if(word[i] == '.') {
                ++i;
                for(short j = 0; j < 26; ++j) {
                    if(nodes[j] && nodes[j]->search(word, i)) {
                        return true;
                    }
                }

                return false;
            }

            return nodes[word[i] - 'a'] ? nodes[word[i] - 'a']->search(word, ++i) : false;
        }

        bool search(string word) {
            return search(word, 0);
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
            cout << inputs[i][j];
            if(j != inputs[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "] ";
    }
    cout << endl;

    WordDictionary* wordDictionary;

    vector<string> results;
    for(int i = 0; i < commands.size(); i++) {
        if(commands[i] == "WordDictionary") {
            wordDictionary = new WordDictionary();
            results.push_back("null");
        } else if(commands[i] == "addWord") {
            wordDictionary->addWord(inputs[i][0]);
            results.push_back("null");
        } else if(commands[i] == "search") {
            results.push_back(wordDictionary->search(inputs[i][0]) ? "true" : "false");
        }
    }

    cout << "Expected: ";
    printArray(expected);

    cout << "Results: ";
    printArray(results);

    cout << endl;
}

int main() {
    test({"WordDictionary", "addWord", "addWord", "addWord", "search", "search", "search", "search"}, {{}, {"bad"}, {"dad"}, {"mad"}, {"pad"}, {"bad"}, {".ad"}, {"b.."}}, {"null", "null", "null", "null", "false", "true", "true", "true"});
    test({"WordDictionary", "addWord", "search", "search"}, {{}, {"a"}, {"."}, {"a"}}, {"null", "null", "true", "true"});
    test({"WordDictionary", "addWord", "addWord", "search", "search"}, {{}, {"abc"}, {"abd"}, {"ab."}, {"a.."}}, {"null", "null", "null", "true", "true"});
    test({"WordDictionary", "addWord", "addWord", "search", "search"}, {{}, {"cat"}, {"dog"}, {"c.t"}, {"..g"}}, {"null", "null", "null", "true", "true"});
    test({"WordDictionary", "addWord", "search", "search"}, {{}, {"hello"}, {"h.llo"}, {"h.ll."}}, {"null", "null", "true", "true"});

    return 0;
}
