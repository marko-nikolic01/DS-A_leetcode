#include <iostream>
#include <vector>

using namespace std;

class TrieNode {
    private:
        vector<TrieNode*> nodes;
        int score;

    public:
        TrieNode() {
            score = 0;
        }

        void insert(string& word, short i) {
            ++score;

            if(i == word.size()) {
                return;
            }

            word[i] -= 'a';

            if(nodes.size() <= word[i]) {
                nodes.resize(word[i] + 1);
            }

            if(!nodes[word[i]]) {
                nodes[word[i]] = new TrieNode();
            }

            nodes[word[i]]->insert(word, ++i);
        }

        void insert(string& word) {
            insert(word, 0);
        }

        int getScore(string& word, short i) {
            return i == word.size() - 1 ? score : score + nodes[word[++i]]->getScore(word, i);
        }

        int getScore(string& word) {
            return nodes[word[0]]->getScore(word, 0);
        }
};

vector<int> sumPrefixScores(vector<string>& words) {
    short n = words.size();
    vector<int> scores(n);
    TrieNode* root = new TrieNode();

    for(short i = 0; i < n; ++i) {
        root->insert(words[i]);
    }

    while(--n > -1) {
        scores[n] = root->getScore(words[n]);
    }

    return scores;
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

void test(vector<string> words, vector<int> expected) {
    cout << "Words: ";
    printArray(words);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(sumPrefixScores(words));

    cout << endl;
}

int main() {
    test({"abc", "ab", "bc", "b"}, {5, 4, 3, 2});
    test({"abcd"}, {4});
    test({"a", "a", "a"}, {3, 3, 3});
    test({"dog", "deer", "deal"}, {5, 7, 7});
    test({"x", "xy", "xyz", "xyza"}, {4, 7, 9, 10});

    return 0;
}
