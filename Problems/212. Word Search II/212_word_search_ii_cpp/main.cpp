#include <iostream>
#include <vector>

using namespace std;

class TrieNode {
    private:
        vector<TrieNode*> nodes;
        vector<short> wordEnds;

    public:
        TrieNode() {}

        void insert(string& word, short index, short i) {
            if(--i < 0) {
                wordEnds.push_back(index);

                return;
            }

            short c = word[i] - '`';

            if(nodes.size() < c) {
                nodes.resize(c);
            }

            if(!nodes[--c]) {
                nodes[c] = new TrieNode();
            }

            nodes[c]->insert(word, index, i);
        }

        void search(vector<vector<char>>& board, vector<string>& words, vector<string>& searchResults, short x, short y) {
            while(!wordEnds.empty()) {
                searchResults.push_back(words[wordEnds.back()]);
                wordEnds.pop_back();
            }

            if(x > -1 && x < board.size() && y > -1 && y < board[0].size()) {
                short c = board[x][y] - 'a';

                if(c > -1 && nodes.size() > c && nodes[c]) {
                    board[x][y] = '`';
                    nodes[c]->search(board, words, searchResults, x - 1, y);
                    nodes[c]->search(board, words, searchResults, x + 1, y);
                    nodes[c]->search(board, words, searchResults, x, y - 1);
                    nodes[c]->search(board, words, searchResults, x, y + 1);
                    board[x][y] = c + 'a';
                }
            }
        }
};

class Trie {
    private:
        TrieNode* trie;

        void insert(string& word, short index) {
            trie->insert(word, index, word.length());
        }

        void search(vector<vector<char>>& board, vector<string>& words, vector<string>& searchResults, short x, short y) {
            trie->search(board, words, searchResults, x, y);
        }

    public:
        Trie() : trie(new TrieNode()) {}

        void insert(vector<string>& words) {
            for(short i = words.size() - 1; i > -1; --i) {
                insert(words[i], i);
            }
        }

        void search(vector<vector<char>>& board, vector<string>& words, vector<string>& searchResults) {
            short y;
            short m = board.size();
            short n = board[0].size();
            for(short x = 0; x < m; ++x) {
                for(y = 0; y < n; ++y) {
                    search(board, words, searchResults, x, y);
                }
            }
        }
};

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> searchResults;
    Trie* trie = new Trie();

    trie->insert(words);
    trie->search(board, words, searchResults);

    return searchResults;
}

void printArray(vector<string> array) {
    for(string a : array) {
        cout << "\"" << a << "\"" << " ";
    }
    cout << endl;
}

void printMatrix(vector<vector<char>> matrix) {
    for(vector<char> row : matrix) {
        for(char cell : row) {
            cout << "'" << cell << "'" << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<char>> board, vector<string> words, vector<string> expected) {
    cout << "Board:" << endl;
    printMatrix(board);

    cout << "Words: ";
    printArray(words);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(findWords(board, words));

    cout << endl;
}

int main() {
    test({{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}}, {"oath", "pea", "eat", "rain"}, {"eat", "oath"});
    test({{'a', 'b'}, {'c', 'd'}}, {"abcb"}, {});
    test({{'a'}}, {"a"}, {"a"});
    test({{'a'}}, {"b"}, {});
    test({{'a', 'b'}, {'c', 'd'}}, {"ab", "cd"}, {"ab", "cd"});

    return 0;
}
