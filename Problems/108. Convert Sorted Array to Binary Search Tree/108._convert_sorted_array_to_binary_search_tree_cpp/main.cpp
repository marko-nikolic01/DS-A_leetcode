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

TreeNode* sortedArrayToBST(vector<int>& nums, int a, int b) {
    if(a > b) {
        return nullptr;
    }

    int c = (a + b) / 2;

    TreeNode* root = new TreeNode(nums[c]);
    root->left = sortedArrayToBST(nums, a, c - 1);
    root->right = sortedArrayToBST(nums, c + 1, b);

    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBST(nums, 0, nums.size() - 1);
}

void printTree(TreeNode* root) {
    if (root == nullptr) {
        cout << "Tree is empty." << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();
        while (levelSize > 0) {
            TreeNode* node = q.front();
            q.pop();
            if (node != nullptr) {
                cout << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            } else {
                cout << "null ";
            }
            levelSize--;
        }
        cout << endl;
    }
}

int main() {
    vector<int> nums1 = {1, 2, 3};
    TreeNode* root1 = sortedArrayToBST(nums1);
    cout << "Test Case 1:" << endl;
    printTree(root1);

    vector<int> nums2 = {1, 2, 3, 4};
    TreeNode* root2 = sortedArrayToBST(nums2);
    cout << "Test Case 2:" << endl;
    printTree(root2);

    vector<int> nums3 = {1, 2, 3, 4, 5, 6, 7};
    TreeNode* root3 = sortedArrayToBST(nums3);
    cout << "Test Case 3:" << endl;
    printTree(root3);

    return 0;
}
