#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
    int n = s.length();
    vector<vector<int>> graph(n);
    vector<bool> visited(n, false);
    vector<int> indicies;
    string letters = "";

    int i;
    for(i = pairs.size() - 1; i > -1; --i) {
        graph[pairs[i][0]].push_back(pairs[i][1]);
        graph[pairs[i][1]].push_back(pairs[i][0]);
    }

    int j;
    while(--n > -1) {
        if(!visited[n]) {
            indicies.resize(0);
            letters.resize(0);
            indicies.push_back(n);
            letters.push_back(s[n]);
            visited[n] = true;

            for(i = 0; i < indicies.size(); ++i) {
                for(j = graph[indicies[i]].size() - 1; j > -1; --j) {
                    if(!visited[graph[indicies[i]][j]]) {
                        indicies.push_back(graph[indicies[i]][j]);
                        letters.push_back(s[graph[indicies[i]][j]]);
                        visited[graph[indicies[i]][j]] = true;
                    }
                }
            }

            sort(indicies.begin(), indicies.end());
            sort(letters.begin(), letters.end());

            while(--i > -1) {
                s[indicies[i]] = letters[i];
            }
        }
    }

    return s;
}

void test(string s, vector<vector<int>> pairs, string expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Pairs: ";
    for(vector<int> pair : pairs) {
        cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << smallestStringWithSwaps(s, pairs) << "\"" << endl;

    cout << endl;
}

int main() {
    test("dcab", {{0, 3}, {1, 2}}, "bacd");
    test("dcab", {{0, 3}, {1, 2}, {0, 2}}, "abcd");
    test("cba", {{0, 1}, {1, 2}}, "abc");
    test("a", {}, "a");
    test("zya", {{0, 1}, {0, 2}}, "ayz");

    return 0;
}
