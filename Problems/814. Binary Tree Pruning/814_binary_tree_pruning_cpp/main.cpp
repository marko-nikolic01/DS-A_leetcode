#include <iostream>
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

TreeNode* pruneTree(TreeNode* root) {
    if(root->left && !pruneTree(root->left)) {
        root->left = nullptr;
    }

    if(root->right && !pruneTree(root->right)) {
        root->right = nullptr;
    }

    return root->left || root->right || root->val > 0 ? root : nullptr;
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

void test(TreeNode* root, TreeNode* expected) {
    cout << "Tree: ";
    printTree(root);

    cout << "Expected: ";
    printTree(expected);

    cout << "Result: ";
    printTree(pruneTree(root));

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->right = new TreeNode(0);
    root1->right->left = new TreeNode(0);
    root1->right->right = new TreeNode(1);
    TreeNode* expected1 = new TreeNode(1);
    expected1->right = new TreeNode(0);
    expected1->right->right = new TreeNode(1);
    test(root1, expected1);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(0);
    root2->right = new TreeNode(1);
    root2->left->left = new TreeNode(0);
    root2->left->right = new TreeNode(0);
    root2->right->left = new TreeNode(0);
    root2->right->right = new TreeNode(1);
    TreeNode* expected2 = new TreeNode(1);
    expected2->right = new TreeNode(1);
    expected2->right->right = new TreeNode(1);
    test(root2, expected2);

    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(1);
    root3->right = new TreeNode(0);
    root3->left->left = new TreeNode(1);
    root3->left->right = new TreeNode(1);
    root3->right->left = new TreeNode(0);
    root3->right->right = new TreeNode(1);
    TreeNode* expected3 = new TreeNode(1);
    expected3->left = new TreeNode(1);
    expected3->right = new TreeNode(0);
    expected3->left->left = new TreeNode(1);
    expected3->left->right = new TreeNode(1);
    expected3->right->right = new TreeNode(1);
    test(root3, expected3);

    TreeNode* root4 = new TreeNode(1);
    root4->left = new TreeNode(0);
    root4->right = new TreeNode(0);
    TreeNode* expected4 = new TreeNode(1);
    test(root4, expected4);

    TreeNode* root5 = new TreeNode(1);
    root5->right = new TreeNode(0);
    TreeNode* expected5 = new TreeNode(1);
    test(root5, expected5);

    return 0;
}
