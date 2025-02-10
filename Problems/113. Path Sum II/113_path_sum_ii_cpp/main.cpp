#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void pathSum(vector<vector<int>>& paths, vector<int>& path, TreeNode* root, int& targetSum) {
    targetSum -= root->val;
    path.push_back(root->val);

    if(root->left) {
        pathSum(paths, path, root->left, targetSum);

        if(root->right) {
            pathSum(paths, path, root->right, targetSum);
        }
    } else if(root->right) {
        pathSum(paths, path, root->right, targetSum);
    } else if(targetSum == 0) {
        paths.push_back(path);
    }

    targetSum += root->val;
    path.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    if(!root) {
        return {};
    }

    vector<vector<int>> paths;
    vector<int> path;

    pathSum(paths, path, root, targetSum);

    return paths;
}

void printTree(TreeNode* root) {
    if (!root) {
        cout << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
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

void test(TreeNode* root, int targetSum, vector<vector<int>> expected) {
    cout << "Tree:";
    printTree(root);

    cout << "Target sum: " << targetSum << endl;

    cout << "Expected: ";
    for(vector<int> e : expected) {
        cout << "[";
        for(int i = 0; i < e.size(); ++i) {
            cout << e[i];
            if(i < e.size() - 1) {
                cout << " ";
            }
        }
        cout << "] ";
    }
    cout << endl;

    cout << "Result: ";
    for(vector<int> result : pathSum(root, targetSum)) {
        cout << "[";
        for(int i = 0; i < result.size(); ++i) {
            cout << result[i];
            if(i < result.size() - 1) {
                cout << " ";
            }
        }
        cout << "] ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(5);
    root1->left = new TreeNode(4);
    root1->left->left = new TreeNode(11);
    root1->left->left->left = new TreeNode(7);
    root1->left->left->right = new TreeNode(2);
    root1->right = new TreeNode(8);
    root1->right->left = new TreeNode(13);
    root1->right->right = new TreeNode(4);
    root1->right->right->left = new TreeNode(5);
    root1->right->right->right = new TreeNode(1);
    test(root1, 22, {{5, 4, 11, 2}, {5, 8, 4, 5}});

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    test(root2, 5, {});

    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    test(root3, 0, {});

    TreeNode* root4 = new TreeNode(7);
    test(root4, 7, {{7}});

    TreeNode* root5 = new TreeNode(-5);
    test(root5, 0, {});

    TreeNode* root6 = new TreeNode(1);
    root6->left = new TreeNode(2);
    root6->left->left = new TreeNode(3);
    root6->left->right = new TreeNode(4);
    root6->right = new TreeNode(5);
    root6->right->left = new TreeNode(6);
    root6->right->right = new TreeNode(1);
    test(root6, 7, {{1, 2, 4}, {1, 5, 1}});

    TreeNode* root7 = nullptr;
    test(root7, 10, {});

    return 0;
}
