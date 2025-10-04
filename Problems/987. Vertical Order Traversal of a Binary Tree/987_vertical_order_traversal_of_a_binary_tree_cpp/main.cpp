#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void verticalTraversal(TreeNode* node, vector<vector<vector<short>>>& columns, short row, short column) {
    if(columns.size() == column) {
        columns.push_back({});
    }

    if(columns[column].size() <= row) {
        columns[column].resize(row + 1);
    }

    columns[column][row].push_back(node->val);
}

void verticalTraversal(TreeNode* node, vector<vector<vector<short>>>& positiveColumns, vector<vector<vector<short>>>& negativeColumns, short row, short column) {
    if(!node) {
        return;
    }

    if(column < 0) {
        verticalTraversal(node, negativeColumns, row, -column - 1);
    } else {
        verticalTraversal(node, positiveColumns, row, column);
    }

    verticalTraversal(node->left, positiveColumns, negativeColumns, ++row, column - 1);
    verticalTraversal(node->right, positiveColumns, negativeColumns, row, ++column);
}

vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<vector<short>>> positiveColumns;
    vector<vector<vector<short>>> negativeColumns;

    verticalTraversal(root, positiveColumns, negativeColumns, 0, 0);

    short i = negativeColumns.size();
    short n = positiveColumns.size();
    vector<vector<int>> traversal(n + i);
    short iTraversal = 0;

    short j;
    short k;
    short m;
    short l;
    for(--i; i > -1; --i) {
        m = negativeColumns[i].size();
        for(j = 0; j < m; ++j) {
            sort(negativeColumns[i][j].begin(), negativeColumns[i][j].end());

            l = negativeColumns[i][j].size();
            for(k = 0; k < l; ++k) {
                traversal[iTraversal].push_back(negativeColumns[i][j][k]);
            }
        }

        ++iTraversal;
    }

    for(i = 0; i < n; ++i) {
        m = positiveColumns[i].size();
        for(j = 0; j < m; ++j) {
            sort(positiveColumns[i][j].begin(), positiveColumns[i][j].end());

            l = positiveColumns[i][j].size();
            for(k = 0; k < l; ++k) {
                traversal[iTraversal].push_back(positiveColumns[i][j][k]);
            }
        }

        ++iTraversal;
    }

    return traversal;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void printTree(TreeNode* root) {
    if(!root) {
        cout << endl;
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        cout << endl;
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                cout << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            }
        }
    }
}

void test(TreeNode* root, vector<vector<int>> expected) {
    cout << "Tree: ";
    printTree(root);

    cout << "Expected:" << endl;
    printMatrix(expected);

    cout << "Result:" << endl;
    printMatrix(verticalTraversal(root));

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);
    vector<vector<int>> expected1 = {{9}, {3, 15}, {20}, {7}};
    test(root1, expected1);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);
    root2->right->left = new TreeNode(6);
    root2->right->right = new TreeNode(7);
    vector<vector<int>> expected2 = {{4}, {2}, {1, 5, 6}, {3}, {7}};
    test(root2, expected2);

    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(3);
    root3->left->left = new TreeNode(4);
    root3->left->right = new TreeNode(6);
    root3->right->left = new TreeNode(5);
    root3->right->right = new TreeNode(7);
    vector<vector<int>> expected3 = {{4}, {2}, {1, 5, 6}, {3}, {7}};
    test(root3, expected3);

    TreeNode* root4 = new TreeNode(10);
    vector<vector<int>> expected4 = {{10}};
    test(root4, expected4);

    TreeNode* root5 = new TreeNode(1);
    root5->left = new TreeNode(2);
    root5->left->left = new TreeNode(3);
    root5->left->left->left = new TreeNode(4);
    vector<vector<int>> expected5 = {{4}, {3}, {2}, {1}};
    test(root5, expected5);

    return 0;
}
