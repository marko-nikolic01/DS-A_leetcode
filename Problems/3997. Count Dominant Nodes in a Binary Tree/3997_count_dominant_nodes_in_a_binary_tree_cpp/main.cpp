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

int countDominantNodes(TreeNode* root) {
    int dominant = 0;
    bool isDominant = true;

    if(root->left) {
        dominant += countDominantNodes(root->left);

        if(root->left->val > root->val) {
            root->val = root->left->val;
            isDominant = false;
        }
    }

    if(root->right) {
        dominant += countDominantNodes(root->right);

        if(root->right->val > root->val) {
            root->val = root->right->val;
            isDominant = false;
        }
    }

    return isDominant ? ++dominant : dominant;
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

void test(TreeNode* root, int expected) {
    cout << "Tree:";
    printTree(root);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countDominantNodes(root) << endl;

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(5);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(8);
    root1->left->left = new TreeNode(2);
    root1->left->right = new TreeNode(4);
    root1->right->left = new TreeNode(7);
    root1->right->right = new TreeNode(1);
    test(root1, 5);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(1);
    root2->left->right = new TreeNode(2);
    test(root2, 4);

    TreeNode* root3 = new TreeNode(10);
    test(root3, 1);

    TreeNode* root4 = new TreeNode(10);
    root4->left = new TreeNode(5);
    root4->right = new TreeNode(6);
    root4->left->left = new TreeNode(1);
    root4->left->right = new TreeNode(2);
    root4->right->left = new TreeNode(3);
    root4->right->right = new TreeNode(4);
    test(root4, 7);

    TreeNode* root5 = new TreeNode(4);
    root5->left = new TreeNode(4);
    root5->right = new TreeNode(4);
    root5->left->left = new TreeNode(4);
    root5->left->right = new TreeNode(4);
    root5->right->left = new TreeNode(4);
    root5->right->right = new TreeNode(4);
    test(root5, 7);

    return 0;
}
