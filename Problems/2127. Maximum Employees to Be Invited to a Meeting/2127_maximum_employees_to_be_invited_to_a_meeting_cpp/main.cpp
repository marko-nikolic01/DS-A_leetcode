#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void maximumInvitations(vector<vector<int>>& parents, int employee, int length, int& invitations,  vector<bool>& loops) {
    ++length;

    int n = parents[employee].size();
    if(n < 1) {
        if(length > invitations) {
            invitations = length;
        }

        return;
    }

    for(--n; n > -1; --n) {
        maximumInvitations(parents, parents[employee][n], length, invitations, loops);
    }

    loops[employee] = true;
}

int maximumInvitations(vector<int>& favorite) {
    int n = favorite.size();
    vector<vector<int>> parents(n);
    vector<bool> loops(n, false);

    for(int i = 0; i < n; ++i) {
        parents[favorite[i]].push_back(i);
    }

    int invitations = 0;
    int currentInvitations;

    int m;
    for(int i = 0; i < n; ++i) {
        if(i == favorite[favorite[i]]) {
            m = parents[i].size();
            if(m < 2) {
                ++invitations;
            } else {
                currentInvitations = 1;

                for(--m; m > -1; --m) {
                    if(parents[i][m] != favorite[i]) {
                        maximumInvitations(parents, parents[i][m], 1, currentInvitations, loops);
                    }
                }

                invitations += currentInvitations;
            }

            loops[i] = true;
        }
    }

    stack<int> traversal;

    for(--n; n > -1; --n) {
        if(!loops[n]) {
            traversal.push(n);
            loops[n] = true;

            while(!loops[favorite[traversal.top()]]) {
                traversal.push(favorite[traversal.top()]);
                loops[traversal.top()] = true;
            }

            currentInvitations = 1;
            m = favorite[traversal.top()];

            while(!traversal.empty()) {
                if(traversal.top() == m) {
                    while(!traversal.empty()) {
                        traversal.pop();
                    }

                    if(currentInvitations > invitations) {
                        invitations = currentInvitations;
                    }

                    break;
                }

                ++currentInvitations;
                traversal.pop();
            }
        }
    }

    return invitations;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> favorite, int expected) {
    cout << "Favorites: ";
    printArray(favorite);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maximumInvitations(favorite) << endl;

    cout << endl;
}

int main() {
    test({2, 2, 1, 2}, 3);
    test({1, 2, 0}, 3);
    test({3, 0, 1, 4, 1}, 4);
    test({1, 0}, 2);
    test({1, 0, 0, 2, 1, 4, 7, 8, 9, 6, 7, 10, 8}, 6);

    return 0;
}
