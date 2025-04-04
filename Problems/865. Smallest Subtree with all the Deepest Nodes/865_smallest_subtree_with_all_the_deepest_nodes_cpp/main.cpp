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

void subtreeWithAllDeepest(TreeNode* root, TreeNode*& child, short& depth) {
    TreeNode* leftChild = nullptr;
    short leftDepth = 0;
    if(root->left) {
        subtreeWithAllDeepest(root->left, leftChild, leftDepth);
    }

    TreeNode* rightChild = nullptr;
    short rightDepth = 0;
    if(root->right) {
        subtreeWithAllDeepest(root->right, rightChild, rightDepth);
    }

    if(leftDepth > rightDepth) {
        child = leftChild;
        depth = ++leftDepth;
    } else if(rightDepth > leftDepth) {
        child = rightChild;
        depth = ++rightDepth;
    } else {
        child = root;
        depth = ++leftDepth;
    }
}

TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    TreeNode* child = nullptr;
    short depth = 0;

    subtreeWithAllDeepest(root, child, depth);

    return child;
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
    cout << "Tree:";
    printTree(root);

    cout << "Expected:";
    printTree(expected);

    cout << "Result:";
    printTree(subtreeWithAllDeepest(root));

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(1);
    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(2);
    root1->left->right->left = new TreeNode(7);
    root1->left->right->right = new TreeNode(4);
    root1->right->left = new TreeNode(0);
    root1->right->right = new TreeNode(8);
    TreeNode* expected1 = root1->left->right;
    test(root1, expected1);

    TreeNode* root2 = new TreeNode(1);
    TreeNode* expected2 = root2;
    test(root2, expected2);

    TreeNode* root3 = new TreeNode(0);
    root3->left = new TreeNode(1);
    root3->left->right = new TreeNode(2);
    TreeNode* expected3 = root3->left->right;
    test(root3, expected3);

    TreeNode* root4 = new TreeNode(1);
    root4->left = new TreeNode(2);
    root4->right = new TreeNode(3);
    TreeNode* expected4 = root4;
    test(root4, expected4);

    TreeNode* root5 = new TreeNode(1);
    root5->right = new TreeNode(2);
    root5->right->right = new TreeNode(3);
    TreeNode* expected5 = root5->right->right;
    test(root5, expected5);

    TreeNode* root6 = new TreeNode(0);
    root6->left = new TreeNode(1);
    root6->right = new TreeNode(3);
    root6->left->right = new TreeNode(2);
    TreeNode* expected6 = root6->left->right;
    test(root6, expected6);

    return 0;
}
