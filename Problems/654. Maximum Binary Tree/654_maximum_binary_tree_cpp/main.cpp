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

TreeNode* constructMaximumBinaryTree(vector<int>& nums, short left, short right) {
    if(left > right) {
        return nullptr;
    }

    short max = left;

    for(short i = left + 1; i <= right; ++i) {
        if(nums[i] > nums[max]) {
            max = i;
        }
    }

    return new TreeNode(nums[max], constructMaximumBinaryTree(nums, left, max - 1), constructMaximumBinaryTree(nums, max + 1, right));
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return constructMaximumBinaryTree(nums, 0, nums.size() - 1);
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
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

void test(vector<int> nums, TreeNode* expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Expected";
    printTree(expected);

    cout << "Result:";
    printTree(constructMaximumBinaryTree(nums));

    cout << endl;
}

int main() {
    vector<int> nums1 = {3,2,1,6,0,5};
    TreeNode* expected1 = new TreeNode(6);
    expected1->left = new TreeNode(3);
    expected1->right = new TreeNode(5);
    expected1->left->right = new TreeNode(2);
    expected1->right->left = new TreeNode(0);
    expected1->left->right->right = new TreeNode(1);
    test(nums1, expected1);

    vector<int> nums2 = {3,2,1};
    TreeNode* expected2 = new TreeNode(3);
    expected2->right = new TreeNode(2);
    expected2->right->right = new TreeNode(1);
    test(nums2, expected2);

    vector<int> nums3 = {5,4,3,2,1};
    TreeNode* expected3 = new TreeNode(5);
    expected3->right = new TreeNode(4);
    expected3->right->right = new TreeNode(3);
    expected3->right->right->right = new TreeNode(2);
    expected3->right->right->right->right = new TreeNode(1);
    test(nums3, expected3);

    vector<int> nums4 = {1,2,3,4,5};
    TreeNode* expected4 = new TreeNode(5);
    expected4->left = new TreeNode(4);
    expected4->left->left = new TreeNode(3);
    expected4->left->left->left = new TreeNode(2);
    expected4->left->left->left->left = new TreeNode(1);
    test(nums4, expected4);

    vector<int> nums5 = {42};
    TreeNode* expected5 = new TreeNode(42);
    test(nums5, expected5);

    vector<int> nums6 = {7,1,5,9,2};
    TreeNode* expected6 = new TreeNode(9);
    expected6->left = new TreeNode(7);
    expected6->right = new TreeNode(2);
    expected6->left->right = new TreeNode(5);
    expected6->left->right->left = new TreeNode(1);
    test(nums6, expected6);

    return 0;
}
