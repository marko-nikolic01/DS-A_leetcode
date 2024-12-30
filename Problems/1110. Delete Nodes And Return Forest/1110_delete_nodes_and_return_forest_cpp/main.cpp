#include <iostream>
#include <vector>
#include <unordered_set>
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

bool delNodes(TreeNode* root, unordered_set<int>& nodesToDelete, vector<TreeNode*>& forest, bool hasParent) {
    if(!hasParent) {
        hasParent = nodesToDelete.find(root->val) != nodesToDelete.end();
        if(!hasParent) {
            forest.push_back(root);
        }
    } else {
        hasParent = nodesToDelete.find(root->val) != nodesToDelete.end();
    }

    if(root->left && delNodes(root->left, nodesToDelete, forest, !hasParent)) {
        root->left = nullptr;
    }

    if(root->right && delNodes(root->right, nodesToDelete, forest, !hasParent)) {
        root->right = nullptr;
    }

    return hasParent;
}

vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    vector<TreeNode*> forest;

    unordered_set<int> nodesToDelete(to_delete.begin(), to_delete.end());

    delNodes(root, nodesToDelete, forest, false);

    return forest;
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
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* current = q.front();
            q.pop();

            if (current) {
                cout << current->val << " ";
                q.push(current->left);
                q.push(current->right);
            }
        }
    }
}

void printTreeAsArray(TreeNode* root) {
    if (!root) {
        cout << "null ";
        return;
    }

    cout << "[";

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        if (current) {
            cout << current->val << "";
            q.push(current->left);
            q.push(current->right);
        } else {
            cout << "null";
        }

        if(!q.empty()) {
            cout << " ";
        }
    }
    cout << "] ";
}

void test(TreeNode* root, vector<int>& to_delete, vector<TreeNode*>& expected) {
    cout << "Tree: ";
    printTree(root);

    cout << "Nodes to delete: ";
    for (int val : to_delete) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Expected: ";
    for (TreeNode* e : expected) {
        printTreeAsArray(e);
    }
    cout << endl;

    cout << "Result: ";
    for (TreeNode* result : delNodes(root, to_delete)) {
        printTreeAsArray(result);
    }
    cout << endl;

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(7);
    vector<int> to_delete1 = {3, 5};
    vector<TreeNode*> expected1;
    expected1.push_back(new TreeNode(1));
    expected1[0]->left = new TreeNode(2);
    expected1[0]->left->left = new TreeNode(4);
    expected1.push_back(new TreeNode(6));
    expected1.push_back(new TreeNode(7));
    test(root1, to_delete1, expected1);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->left->left = new TreeNode(3);
    vector<int> to_delete2 = {3};
    vector<TreeNode*> expected2;
    expected2.push_back(new TreeNode(1));
    expected2[0]->left = new TreeNode(2);
    expected2[0]->left->left = nullptr;
    test(root2, to_delete2, expected2);

    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(4);
    root3->right->left = new TreeNode(3);
    vector<int> to_delete3 = {2, 4};
    vector<TreeNode*> expected3;
    expected3.push_back(new TreeNode(1));
    expected3[0]->left = nullptr;
    expected3[0]->right = nullptr;
    expected3.push_back(new TreeNode(3));
    test(root3, to_delete3, expected3);

    TreeNode* root4 = new TreeNode(1);
    vector<int> to_delete4 = {1};
    vector<TreeNode*> expected4;
    test(root4, to_delete4, expected4);

    TreeNode* root5 = new TreeNode(1);
    vector<int> to_delete5 = {};
    vector<TreeNode*> expected5;
    expected5.push_back(new TreeNode(1));
    test(root5, to_delete5, expected5);

    return 0;
}
