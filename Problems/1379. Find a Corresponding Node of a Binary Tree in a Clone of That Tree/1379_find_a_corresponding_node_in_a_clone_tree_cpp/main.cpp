#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* getTargetCopy(TreeNode* cloned, int target) {
    if(cloned->val == target) {
        return cloned;
    }

    TreeNode* copy = nullptr;
    if(cloned->left) {
        copy = getTargetCopy(cloned->left, target);
    }

    return copy || !cloned->right ? copy : getTargetCopy(cloned->right, target);
}

TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    return getTargetCopy(cloned, target->val);;
}

void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; ++i) {
            TreeNode* current = q.front();
            q.pop();

            cout << current->val << " ";

            if (current->left != nullptr) q.push(current->left);
            if (current->right != nullptr) q.push(current->right);
        }
        cout << endl;
    }
}

void testGetTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    cout << "Original tree:" << endl;
    printTree(original);

    cout << "Cloned tree:" << endl;
    printTree(cloned);

    cout << "Expected:" << endl;
    printTree(target);

    cout << "Result:" << endl;
    printTree(getTargetCopy(original, cloned, target));

    cout << endl;
}

int main() {
    TreeNode* original1 = new TreeNode(1);
    original1->left = new TreeNode(2);
    original1->right = new TreeNode(3);
    original1->left->left = new TreeNode(4);
    original1->left->right = new TreeNode(5);
    original1->right->left = new TreeNode(6);
    original1->right->right = new TreeNode(7);
    TreeNode* cloned1 = new TreeNode(1);
    cloned1->left = new TreeNode(2);
    cloned1->right = new TreeNode(3);
    cloned1->left->left = new TreeNode(4);
    cloned1->left->right = new TreeNode(5);
    cloned1->right->left = new TreeNode(6);
    cloned1->right->right = new TreeNode(7);
    TreeNode* target1 = original1->left->right;
    testGetTargetCopy(original1, cloned1, target1);

    TreeNode* original2 = new TreeNode(10);
    original2->left = new TreeNode(20);
    original2->right = new TreeNode(30);
    original2->left->left = new TreeNode(40);
    original2->right->right = new TreeNode(50);
    TreeNode* cloned2 = new TreeNode(10);
    cloned2->left = new TreeNode(20);
    cloned2->right = new TreeNode(30);
    cloned2->left->left = new TreeNode(40);
    cloned2->right->right = new TreeNode(50);
    TreeNode* target2 = original2->right->right;
    testGetTargetCopy(original2, cloned2, target2);

    TreeNode* original3 = new TreeNode(5);
    original3->left = new TreeNode(3);
    original3->right = new TreeNode(8);
    original3->left->left = new TreeNode(1);
    original3->left->right = new TreeNode(4);
    TreeNode* cloned3 = new TreeNode(5);
    cloned3->left = new TreeNode(3);
    cloned3->right = new TreeNode(8);
    cloned3->left->left = new TreeNode(1);
    cloned3->left->right = new TreeNode(4);
    TreeNode* target3 = original3->left;
    testGetTargetCopy(original3, cloned3, target3);

    return 0;
}
