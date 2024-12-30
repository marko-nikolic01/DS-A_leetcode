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

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(!root) {
        return new TreeNode(val);
    }

    if(val < root->val) {
        if(root->left) {
            insertIntoBST(root->left, val);
        } else {
            root->left = insertIntoBST(nullptr, val);
        }
    } else if(root->right) {
        insertIntoBST(root->right, val);
    } else {
        root->right = insertIntoBST(nullptr, val);
    }

    return root;
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

void test(TreeNode* root, int val, TreeNode* expected) {
    cout << "Tree: ";
    printTree(root);

    cout << "Value: " << val << endl;

    cout << "Expected: ";
    printTree(expected);

    cout << "Result: ";
    printTree(insertIntoBST(root, val));

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(4);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(7);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(3);
    TreeNode* expected1 = new TreeNode(4);
    expected1->left = new TreeNode(2);
    expected1->right = new TreeNode(7);
    expected1->left->left = new TreeNode(1);
    expected1->left->right = new TreeNode(3);
    expected1->right->left = new TreeNode(5);
    test(root1, 5, expected1);

    TreeNode* root2 = new TreeNode(40);
    root2->left = new TreeNode(20);
    root2->right = new TreeNode(60);
    root2->left->left = new TreeNode(10);
    root2->left->right = new TreeNode(30);
    root2->right->left = new TreeNode(50);
    root2->right->right = new TreeNode(70);
    TreeNode* expected2 = new TreeNode(40);
    expected2->left = new TreeNode(20);
    expected2->right = new TreeNode(60);
    expected2->left->left = new TreeNode(10);
    expected2->left->right = new TreeNode(30);
    expected2->right->left = new TreeNode(50);
    expected2->right->right = new TreeNode(70);
    expected2->left->right->left = new TreeNode(25);
    test(root2, 25, expected2);

    TreeNode* root3 = nullptr;
    TreeNode* expected3 = new TreeNode(10);
    test(root3, 10, expected3);

    TreeNode* root4 = new TreeNode(5);
    TreeNode* expected4 = new TreeNode(5);
    expected4->right = new TreeNode(8);
    test(root4, 8, expected4);

    TreeNode* root5 = new TreeNode(10);
    TreeNode* expected5 = new TreeNode(10);
    expected5->left = new TreeNode(5);
    test(root5, 5, expected5);

    TreeNode* root6 = new TreeNode(20);
    root6->left = new TreeNode(10);
    root6->right = new TreeNode(30);
    TreeNode* expected6 = new TreeNode(20);
    expected6->left = new TreeNode(10);
    expected6->right = new TreeNode(30);
    expected6->left->left = new TreeNode(5);
    test(root6, 5, expected6);

    TreeNode* root7 = new TreeNode(30);
    root7->left = new TreeNode(20);
    root7->right = new TreeNode(40);
    root7->left->left = new TreeNode(10);
    root7->left->right = new TreeNode(25);
    root7->right->left = new TreeNode(35);
    root7->right->right = new TreeNode(50);
    TreeNode* expected7 = new TreeNode(30);
    expected7->left = new TreeNode(20);
    expected7->right = new TreeNode(40);
    expected7->left->left = new TreeNode(10);
    expected7->left->right = new TreeNode(25);
    expected7->right->left = new TreeNode(35);
    expected7->right->right = new TreeNode(50);
    expected7->left->right->right = new TreeNode(27);
    test(root7, 27, expected7);

    return 0;
}

