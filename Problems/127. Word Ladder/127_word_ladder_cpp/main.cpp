#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool ladderLength(string& word1, string& word2) {
    for(short i = word1.length() - 1; i > -1; --i) {
        if(word1[i] != word2[i]) {
            return false;
        }
    }

    return true;
}

void ladderLength(vector<vector<short>>& graph, string& word1, string& word2, short i1, short i2) {
    bool differences = false;

    for(short i = word1.length() - 1; i > -1; --i) {
        if(word1[i] != word2[i]) {
            if(differences) {
                return;
            }

            differences = true;
        }
    }

    if(differences) {
        graph[i1].push_back(i2);
        graph[i2].push_back(i1);
    }
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    short n = wordList.size();
    vector<vector<short>> graph(n + 2);
    vector<bool> visited(n + 2, false);
    short begin = -1;
    short end = -1;

    short i;
    short j;
    for(i = n - 1; i > -1; --i) {
        if(ladderLength(beginWord, wordList[i])) {
            begin = i;
        } else if(ladderLength(endWord, wordList[i])) {
            end = i;
        }

        for(j = i - 1; j > -1; --j) {
            ladderLength(graph, wordList[i], wordList[j], i, j);
        }
    }

    if(end < 0) {
        return 0;
    }

    if(begin < 0) {
        begin = n;

        for(i = n - 1; i > -1; --i) {
            ladderLength(graph, beginWord, wordList[i], begin, i);
        }
    }

    queue<short> traversal;
    short ladder = 2;

    traversal.push(begin);
    visited[begin] = true;

    while(!traversal.empty()) {
        for(i = traversal.size(); i > 0; --i) {
            n = traversal.front();
            traversal.pop();

            for(j = graph[n].size() - 1; j > -1; --j) {
                if(graph[n][j] == end) {
                    return ladder;
                }

                if(!visited[graph[n][j]]) {
                    traversal.push(graph[n][j]);
                    visited[graph[n][j]] = true;
                }
            }
        }

        ++ladder;
    }

    return 0;
}

void printArray(vector<string> array) {
    for(string a : array) {
        cout << "\"" << a << "\"" << " ";
    }
    cout << endl;
}

void test(string beginWord, string endWord, vector<string> wordList, int expected) {
    cout << "Begin word: " << "\"" << beginWord << "\"" << endl;

    cout << "End word: " << "\"" << endWord << "\"" << endl;

    cout << "Words: ";
    printArray(wordList);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << ladderLength(beginWord, endWord, wordList) << endl;

    cout << endl;
}

int main() {
    test("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}, 5);
    test("hit", "cog", {"hot", "dot", "dog", "lot", "log"}, 0);
    test("a", "c", {"a", "b", "c"}, 2);
    test("lost", "cost", {"most", "fist", "lost", "cost", "fish"}, 2);
    test("talk", "tail", {"tons", "fall", "tail", "gail", "hall", "negs"}, 0);

    return 0;
}
