#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class TrieNode {
    private:
        vector<TrieNode*> nodes;
        short minimumLength;
        short minimumIndex;

        void update(short length, short index) {
            if(length < minimumLength || (length == minimumLength && index < minimumIndex)) {
                minimumLength = length;
                minimumIndex = index;
            }
        }

    public:
        TrieNode() : minimumLength(SHRT_MAX), minimumIndex(-1) {}

        void insert(string& word, short index, short i) {
            if(--i > -1) {
                short c = word[i] - '`';

                if(nodes.size() < c) {
                    nodes.resize(c);
                }

                if(!nodes[--c]) {
                    nodes[c] = new TrieNode();
                }

                nodes[c]->update(word.length(), index);
                nodes[c]->insert(word, index, i);
            }
        }

        short search(string& query, short i) {
            if(--i < 0) {
                return minimumIndex;
            }

            short c = query[i] - 'a';

            return nodes.size() > c && nodes[c] ? nodes[c]->search(query, i) : minimumIndex;
        }
};

class Trie {
    private:
        TrieNode* trie;

    public:
        Trie() : trie(new TrieNode()) {}

        void insert(string& word, short index) {
            trie->insert(word, index, word.length());
        }

        short search(string& query) {
            return trie->search(query, query.length());
        }
};

vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
    short n = wordsQuery.size();
    vector<int> suffixes(n);
    Trie* trie = new Trie();
    short result;
    short shortest = 0;

    short i =  wordsContainer.size();
    while(--i > -1) {
        if(wordsContainer[i].length() <= wordsContainer[shortest].length()) {
            shortest = i;
        }

        trie->insert(wordsContainer[i], i);
    }

    while(--n > -1) {
        i = trie->search(wordsQuery[n]);
        suffixes[n] = i < 0 ? shortest : i;
    }

    return suffixes;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void printArray(vector<string> array) {
    for(string a : array) {
        cout << "\"" << a << "\"" << " ";
    }
    cout << endl;
}

void test(vector<string> wordsContainer, vector<string> wordsQuery, vector<int> expected) {
    cout << "Containers: ";
    printArray(wordsContainer);

    cout << "Queries: ";
    printArray(wordsQuery);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(stringIndices(wordsContainer, wordsQuery));

    cout << endl;
}

int main() {
    test({"abcd", "bcd", "xbcd"}, {"cd", "bcd", "xyz"}, {1, 1, 1});
    test({"abcdefgh", "poiuygh", "ghghgh"}, {"gh", "acbfgh", "acbfegh"}, {2, 0, 2});
    test({"a", "b", "c"}, {"a", "b", "c"}, {0, 1, 2});
    test({"abc", "bc", "c"}, {"c", "bc", "abc"}, {2, 1, 0});
    test({"abcd"}, {"abcd", "bcd", "cd", "d", "x"}, {0, 0, 0, 0, 0});

    return 0;
}
