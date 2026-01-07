#include <iostream>
#include <vector>

using namespace std;

int countHighestScoreNodes(vector<vector<int>>& tree, long& score, int& scoreNodes, int& nodes, int node) {
    long currentScore = 1;
    int children = 1;
    int branchChildren;
    short n = tree[node].size();

    if(n > 0) {
        branchChildren = countHighestScoreNodes(tree, score, scoreNodes, nodes, tree[node][0]);
        currentScore *= branchChildren;
        children += branchChildren;

        if(n > 1) {
            branchChildren = countHighestScoreNodes(tree, score, scoreNodes, nodes, tree[node][1]);
            currentScore *= branchChildren;
            children += branchChildren;
        }
    }

    if(nodes > children) {
        currentScore *= nodes - children;
    }

    if(currentScore > score) {
        score = currentScore;
        scoreNodes = 1;
    } else if(currentScore == score) {
        ++scoreNodes;
    }

    return children;
}

int countHighestScoreNodes(vector<int>& parents) {
    long score = 0;
    int n = parents.size();
    vector<vector<int>> tree(n);

    int i;
    for(i = --n; i > 0; --i) {
        tree[parents[i]].push_back(i);
    }

    countHighestScoreNodes(tree, score, i, ++n, 0);

    return i;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> parents, int expected) {
    cout << "Parents: ";
    printArray(parents);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countHighestScoreNodes(parents) << endl;

    cout << endl;
}

int main() {
    test({-1, 2, 0, 2, 0}, 3);
    test({-1, 2, 0}, 2);
    test({-1, 0, 0, 1, 1, 2, 2}, 1);
    test({-1, 0, 1, 1, 2, 2, 3}, 5);
    test({-1, 0, 0, 2, 1, 1, 2}, 1);

    return 0;
}
