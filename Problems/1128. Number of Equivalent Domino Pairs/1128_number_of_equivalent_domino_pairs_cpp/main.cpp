#include <iostream>
#include <vector>

using namespace std;

int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    int pairs = 0;
    vector<vector<int>> occurences(9, vector<int>(9, 0));

    for(int i = dominoes.size() - 1; i > -1; --i) {
        if(--dominoes[i][0] < --dominoes[i][1]) {
            pairs += occurences[dominoes[i][0]][dominoes[i][1]]++;
        } else {
            pairs += occurences[dominoes[i][1]][dominoes[i][0]]++;
        }
    }

    return pairs;
}

void test(vector<vector<int>> dominoes, int expected) {
    cout << "Dominoes: ";
    for(vector<int> domino : dominoes) {
        cout << "[" << domino[0] << ", " << domino[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numEquivDominoPairs(dominoes) << endl;

    cout << endl;
}

int main() {
    test({{1, 2}, {2, 1}, {3, 4}, {5, 6}}, 1);
    test({{1, 2}, {1, 2}, {1, 1}, {1, 2}, {2, 2}}, 3);
    test({{2, 2}, {2, 2}, {2, 2}}, 3);
    test({{1, 2}, {3, 4}, {5, 6}}, 0);
    test({{1, 2}, {2, 1}, {1, 2}, {2, 1}}, 6);
}
