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

bool evaluateTree(TreeNode* root) {
    if(root->left) {
        if(root->val == 2) {
            return evaluateTree(root->left) || evaluateTree(root->right);
        }
        return evaluateTree(root->left) && evaluateTree(root->right);
    }

    return root->val == 0 ? false : true;
}

void printTree(TreeNode* root) {
    if (!root) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
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
        cout << endl;
    }
}

void test(TreeNode* root, bool expected) {
    cout << "Tree:" << endl;
    printTree(root);

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (evaluateTree(root) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(2, new TreeNode(0), new TreeNode(1));
    test(root1, true);

    TreeNode* root2 = new TreeNode(3, new TreeNode(0), new TreeNode(0));
    test(root2, false);

    TreeNode* root3 = new TreeNode(3, new TreeNode(1), new TreeNode(0));
    test(root3, false);

    TreeNode* root4 = new TreeNode(3, new TreeNode(1), new TreeNode(1));
    test(root4, true);

    TreeNode* root5 = new TreeNode(2, new TreeNode(0), new TreeNode(0));
    test(root5, false);

    TreeNode* root6 = new TreeNode(2, new TreeNode(1), new TreeNode(0));
    test(root6, true);

    TreeNode* root7 = new TreeNode(2, new TreeNode(1), new TreeNode(1));
    test(root7, true);

    TreeNode* root8 = new TreeNode(2, new TreeNode(3, new TreeNode(1), new TreeNode(0)), new TreeNode(1));
    test(root8, true);

    TreeNode* root9 = new TreeNode(3, new TreeNode(3, new TreeNode(1), new TreeNode(1)), new TreeNode(2, new TreeNode(0), new TreeNode(1)));
    test(root9, true);

    TreeNode* root10 = new TreeNode(0);
    test(root10, false);

    TreeNode* root11 = new TreeNode(1);
    test(root11, true);

    return 0;
}
