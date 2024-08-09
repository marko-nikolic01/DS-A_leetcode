#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSymmetric(TreeNode* root1, TreeNode* root2) {
    if(!root1 && !root2) {
        return true;
    } else if(!root1 || !root2 || root1->val != root2->val) {
        return false;
    }

    return isSymmetric(root1->left, root2->right) && isSymmetric(root1->right, root2->left);
}


bool isSymmetric(TreeNode* root) {
    if(!root) {
        return true;
    }

    return isSymmetric(root->left, root->right);
}

int main() {
    TreeNode* t1 = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(2, new TreeNode(4), new TreeNode(3)));
    cout << "Test Case 1: " << (isSymmetric(t1) ? "True" : "False")
         << " | Expected: True" << endl;

    TreeNode* t2 = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(3)), new TreeNode(2, nullptr, new TreeNode(3)));
    cout << "Test Case 2: " << (isSymmetric(t2) ? "True" : "False")
         << " | Expected: False" << endl;

    TreeNode* t3 = new TreeNode(1);
    cout << "Test Case 3: " << (isSymmetric(t3) ? "True" : "False")
         << " | Expected: True" << endl;

    TreeNode* t4 = nullptr;
    cout << "Test Case 4: " << (isSymmetric(t4) ? "True" : "False")
         << " | Expected: True" << endl;

    TreeNode* t5 = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(2, new TreeNode(4), new TreeNode(5)));
    cout << "Test Case 5: " << (isSymmetric(t5) ? "True" : "False")
         << " | Expected: False" << endl;

    return 0;
}
