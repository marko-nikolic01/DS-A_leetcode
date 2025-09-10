#include <iostream>
#include <vector>

using namespace std;

int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
    short i = languages.size();
    vector<vector<bool>> knowsLanguage(i, vector<bool>(n, false));
    vector<vector<bool>> classes(i, vector<bool>(n, false));

    short j;
    for(--i; i > -1; --i) {
        for(j = languages[i].size() - 1; j > -1; --j) {
            knowsLanguage[i][--languages[i][j]] = true;
        }
    }

    vector<short> peopleToTeach(n, 0);
    bool canTalk;

    for(i = friendships.size() - 1; i > -1; --i) {
        canTalk = false;
        --friendships[i][0];
        --friendships[i][1];

        for(j = languages[friendships[i][0]].size() - 1; j > -1; --j) {
            if(knowsLanguage[friendships[i][1]][languages[friendships[i][0]][j]]) {
                canTalk = true;
                break;
            }
        }

        if(canTalk) {
            continue;
        }

        for(j = languages[friendships[i][1]].size() - 1; j > -1; --j) {
            if(knowsLanguage[friendships[i][0]][languages[friendships[i][1]][j]]) {
                canTalk = true;
                break;
            }
        }

        if(canTalk) {
            continue;
        }

        for(j = n - 1; j > -1; --j) {
            if(!knowsLanguage[friendships[i][0]][j] && !classes[friendships[i][0]][j]) {
                ++peopleToTeach[j];
                classes[friendships[i][0]][j] = true;
            }

            if(!knowsLanguage[friendships[i][1]][j] && !classes[friendships[i][1]][j]) {
                ++peopleToTeach[j];
                classes[friendships[i][1]][j] = true;
            }
        }
    }

    i = 0;

    for(j = --n; j > -1; --j) {
        if(peopleToTeach[j] > 0 && (i < 1 || peopleToTeach[j] < i)) {
            i = peopleToTeach[j];
        }
    }

    return i;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(int n, vector<vector<int>> languages, vector<vector<int>> friendships, int expected) {
    cout << "n: " << n << endl;

    cout << "Languages:" << endl;
    printMatrix(languages);

    cout << "Friendships: ";
    for(vector<int> friendship : friendships) {
        cout << "[" << friendship[0] << ", " << friendship[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minimumTeachings(n, languages, friendships) << endl;

    cout << endl;
}

int main() {
    test(2, {{1}, {2}, {1, 2}}, {{1, 2}, {1, 3}, {2, 3}}, 1);
    test(3, {{2}, {1, 3}, {1, 2}, {3}}, {{1, 4}, {1, 2}, {3, 4}, {2, 3}}, 2);
    test(2, {{1, 2}, {1}, {1, 2}}, {{1, 2}, {2, 3}, {1, 3}}, 0);
    test(3, {{1}, {2}, {3}}, {{1, 2}, {2, 3}, {1, 3}}, 2);
    test(4, {{1, 4}, {2}, {3}, {4}}, {{1, 2}, {3, 4}}, 2);

    return 0;
}
