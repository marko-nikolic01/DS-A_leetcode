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

void convertBST(TreeNode* root, int& sum) {
    if(root->right) {
        convertBST(root->right, sum);
    }

    sum += root->val;
    root->val = sum;

    if(root->left) {
        convertBST(root->left, sum);
    }
}

TreeNode* convertBST(TreeNode* root) {
    if(root) {
        int sum = 0;
        convertBST(root, sum);
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

void test(TreeNode* root, TreeNode* expected) {
    cout << "Tree:";
    printTree(root);

    cout << "Expected:";
    printTree(expected);

    cout << "Result:";
    printTree(convertBST(root));

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(4);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(6);
    root1->left->left = new TreeNode(0);
    root1->left->right = new TreeNode(2);
    root1->left->right->right = new TreeNode(3);
    root1->right->left = new TreeNode(5);
    root1->right->right = new TreeNode(7);
    root1->right->right->right = new TreeNode(8);
    TreeNode* expected1 = new TreeNode(30);
    expected1->left = new TreeNode(36);
    expected1->right = new TreeNode(21);
    expected1->left->left = new TreeNode(36);
    expected1->left->right = new TreeNode(35);
    expected1->left->right->right = new TreeNode(33);
    expected1->right->left = new TreeNode(26);
    expected1->right->right = new TreeNode(15);
    expected1->right->right->right = new TreeNode(8);
    test(root1, expected1);

    TreeNode* root2 = new TreeNode(0);
    root2->right = new TreeNode(1);
    TreeNode* expected2 = new TreeNode(1);
    expected2->right = new TreeNode(1);
    test(root2, expected2);

    TreeNode* root3 = new TreeNode(2);
    root3->left = new TreeNode(1);
    root3->right = new TreeNode(3);
    TreeNode* expected3 = new TreeNode(5);
    expected3->left = new TreeNode(6);
    expected3->right = new TreeNode(3);
    test(root3, expected3);

    TreeNode* root4 = new TreeNode(5);
    root4->left = new TreeNode(2);
    root4->right = new TreeNode(7);
    root4->left->left = new TreeNode(1);
    root4->left->right = new TreeNode(3);
    TreeNode* expected4 = new TreeNode(12);
    expected4->left = new TreeNode(17);
    expected4->right = new TreeNode(7);
    expected4->left->left = new TreeNode(18);
    expected4->left->right = new TreeNode(15);
    test(root4, expected4);

    TreeNode* root5 = new TreeNode(10);
    TreeNode* expected5 = new TreeNode(10);
    test(root5, expected5);

    return 0;
}
