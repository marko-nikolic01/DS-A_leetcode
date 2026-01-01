#include <iostream>
#include <vector>

using namespace std;

class Trie {
    private:
        vector<Trie*> nodes;
        bool isWord;

    public:
        Trie() : nodes(26, nullptr) {
            isWord = false;
        }

        void insert(string& word, short i) {
            if(i == word.length()) {
                isWord = true;
                return;
            }

            word[i] -= 'a';

            if(!nodes[word[i]]) {
                nodes[word[i]] = new Trie();
            }

            nodes[word[i]]->insert(word, ++i);
        }

        void insert(string word) {
            insert(word, 0);
        }

        bool search(string& word, short i) {
            return i == word.length() ? isWord : (nodes[word[i] - 'a'] ? nodes[word[i] - 'a']->search(word, ++i) : false);
        }

        bool search(string word) {
            return search(word, 0);
        }

        bool startsWith(string& prefix, short i) {
            return i == prefix.length() ? true : (nodes[prefix[i] - 'a'] ? nodes[prefix[i] - 'a']->startsWith(prefix, ++i) : false);
        }

        bool startsWith(string prefix) {
            return startsWith(prefix, 0);
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

    Trie* trie;

    vector<string> results;
    for(int i = 0; i < commands.size(); i++) {
        if(commands[i] == "Trie") {
            trie = new Trie();
            results.push_back("null");
        } else if(commands[i] == "insert") {
            trie->insert(inputs[i][0]);
            results.push_back("null");
        } else if(commands[i] == "search") {
            results.push_back(trie->search(inputs[i][0]) ? "true" : "false");
        } else if(commands[i] == "startsWith") {
            results.push_back(trie->startsWith(inputs[i][0]) ? "true" : "false");
        }
    }

    cout << "Expected: ";
    printArray(expected);

    cout << "Results: ";
    printArray(results);

    cout << endl;
}

int main() {
    test({"Trie", "insert", "search", "search", "startsWith", "insert", "search"}, {{}, {"apple"}, {"apple"}, {"app"}, {"app"}, {"app"}, {"app"}}, {"null", "null", "true", "false", "true", "null", "true"});
    test({"Trie", "insert", "search", "startsWith"}, {{}, {"hello"}, {"hello"}, {"hell"}}, {"null", "null", "true", "true"});
    test({"Trie", "insert", "search", "startsWith"}, {{}, {"hello"}, {"hell"}, {"hello"}}, {"null", "null", "false", "true"});
    test({"Trie", "insert", "insert", "search", "startsWith"}, {{}, {"dog"}, {"cat"}, {"cat"}, {"do"}}, {"null", "null", "null", "true", "true"});
    test({"Trie", "insert", "search", "startsWith"}, {{}, {"a"}, {"a"}, {"b"}}, {"null", "null", "true", "false"});

    return 0;
}
