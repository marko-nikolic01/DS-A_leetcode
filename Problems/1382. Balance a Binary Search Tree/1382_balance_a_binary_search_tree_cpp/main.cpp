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

void balanceBST(TreeNode* node, vector<int>& traversal) {
    if(node->left) {
        balanceBST(node->left, traversal);
    }

    traversal.push_back(node->val);

    if(node->right) {
        balanceBST(node->right, traversal);
    }
}

TreeNode* balanceBST(vector<int>& traversal, short left, short right) {
    if(left > right) {
        return nullptr;
    }

    short middle = (left + right) >> 1;

    return new TreeNode(traversal[middle], balanceBST(traversal, left, middle - 1), balanceBST(traversal, middle + 1, right));
}

TreeNode* balanceBST(TreeNode* root) {
    vector<int> traversal;

    balanceBST(root, traversal);

    return balanceBST(traversal, 0, traversal.size() - 1);
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

void test(TreeNode* root, TreeNode* expected) {
    cout << "Tree: ";
    printTree(root);

    cout << "Expected: ";
    printTree(expected);

    cout << "Result: ";
    printTree(balanceBST(root));

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->right = new TreeNode(2);
    root1->right->right = new TreeNode(3);
    root1->right->right->right = new TreeNode(4);
    TreeNode* expected1 = new TreeNode(2);
    expected1->left = new TreeNode(1);
    expected1->right = new TreeNode(3);
    expected1->right->right = new TreeNode(4);
    test(root1, expected1);

    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    TreeNode* expected2 = new TreeNode(2);
    expected2->left = new TreeNode(1);
    expected2->right = new TreeNode(3);
    test(root2, expected2);

    TreeNode* root3 = new TreeNode(1);
    TreeNode* expected3 = new TreeNode(1);
    test(root3, expected3);

    TreeNode* root4 = new TreeNode(1);
    root4->right = new TreeNode(2);
    TreeNode* expected4 = new TreeNode(1);
    expected4->right = new TreeNode(2);
    test(root4, expected4);

    TreeNode* root5 = new TreeNode(3);
    root5->left = new TreeNode(2);
    root5->left->left = new TreeNode(1);
    TreeNode* expected5 = new TreeNode(2);
    expected5->left = new TreeNode(1);
    expected5->right = new TreeNode(3);
    test(root5, expected5);

    return 0;
}
