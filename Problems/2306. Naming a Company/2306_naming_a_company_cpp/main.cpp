#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

long long distinctNames(vector<string>& ideas) {
    unordered_set<string> distinctIdeas;

    int n = ideas.size();
    for(int i = 0; i < n; ++i) {
        distinctIdeas.insert(ideas[i]);
    }

    vector<vector<int>> goodLetterCombinations(26, vector<int>(26, 0));
    long names = 0;

    for(--n; n > -1; --n) {
        short c = ideas[n][0] - 'a';

        for(short i = 0; i < c; ++i) {
            ideas[n][0] = i + 'a';

            if(distinctIdeas.find(ideas[n]) == distinctIdeas.end()) {
                ++goodLetterCombinations[c][i];
                names += goodLetterCombinations[i][c];
            }
        }

        for(short i = c + 1; i < 26; ++i) {
            ideas[n][0] = i + 'a';

            if(distinctIdeas.find(ideas[n]) == distinctIdeas.end()) {
                ++goodLetterCombinations[c][i];
                names += goodLetterCombinations[i][c];
            }
        }
    }

    return 2 * names;
}

void test(vector<string> ideas, long long expected) {
    cout << "Ideas: ";
    for(string idea : ideas) {
        cout << "\"" << idea << "\" ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << distinctNames(ideas) << endl;

    cout << endl;
}

int main() {
    test({"coffee", "donuts", "time", "toffee"}, 6);
    test({"lack", "back"}, 0);
    test({"apple", "ample", "sample", "maple"}, 10);
    test({"alpha", "beta", "gamma", "delta"}, 12);
    test({"cat", "bat", "rat", "mat", "pat"}, 0);

    return 0;
}
