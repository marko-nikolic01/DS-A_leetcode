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

int sumRootToLeaf(TreeNode* root, int currentSum) {
    currentSum *= 2;

    if(root->val == 1) {
        currentSum++;
    }

    if(!root->left && !root->right) {
        return currentSum;
    }

    int sum = 0;

    if(root->left) {
        sum += sumRootToLeaf(root->left, currentSum);
    }

    if(root->right) {
        sum += sumRootToLeaf(root->right, currentSum);
    }

    return sum;
}

int sumRootToLeaf(TreeNode* root) {
    return sumRootToLeaf(root, 0);
}

void printTree(TreeNode* root) {
    if(!root) {
        cout << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();
        for(int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();
            if(node) {
                cout << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            }
        }
        if(!q.empty()) {
            cout << endl;
        }
    }
}

void test(TreeNode* root, int expected) {
    cout << "Tree:" << endl;;
    printTree(root);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << sumRootToLeaf(root) << endl;

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(1, new TreeNode(0, new TreeNode(0), new TreeNode(1)), new TreeNode(1, new TreeNode(0), new TreeNode(1)));
    test(root1, 22);

    TreeNode* root2 = new TreeNode(1, new TreeNode(1), new TreeNode(0));
    test(root2, 5);

    TreeNode* root3 = new TreeNode(0);
    test(root3, 0);

    TreeNode* root4 = new TreeNode(1, new TreeNode(1, new TreeNode(1), new TreeNode(1)), new TreeNode(0, new TreeNode(1), new TreeNode(1)));
    test(root4, 24);

    TreeNode* root5 = new TreeNode(1, new TreeNode(0), new TreeNode(1));
    test(root5, 5);

    TreeNode* root6 = new TreeNode(1, new TreeNode(1, nullptr, new TreeNode(1)), new TreeNode(0));
    test(root6, 9);

    TreeNode* root7 = new TreeNode(1);
    test(root7, 1);

    return 0;
}
