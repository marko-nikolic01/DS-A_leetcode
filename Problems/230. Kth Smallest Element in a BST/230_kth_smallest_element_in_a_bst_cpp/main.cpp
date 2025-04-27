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

int kthSmallest(TreeNode* root, int k) {
    if(root->left) {
        k = kthSmallest(root->left, k);

        if(k > -1) {
            return k;
        } else {
            k = -k;
        }
    }

    if(k == 1) {
        return root->val;
    }

    --k;

    if(root->right) {
        k = kthSmallest(root->right, k);

        if(k > -1) {
            return k;
        } else {
            k = -k;
        }
    }

    return -k;
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

void test(TreeNode* root, int k, int expected) {
    cout << "Tree:";
    printTree(root);

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << kthSmallest(root, k) << endl;

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);
    test(root1, 2, 2);

    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(2);
    root2->left->left = new TreeNode(1);
    test(root2, 1, 1);

    TreeNode* root3 = new TreeNode(3);
    root3->left = new TreeNode(1);
    root3->right = new TreeNode(4);
    root3->left->right = new TreeNode(2);
    test(root3, 1, 1);

    TreeNode* root4 = new TreeNode(5);
    root4->left = new TreeNode(3);
    root4->right = new TreeNode(6);
    root4->left->left = new TreeNode(2);
    root4->left->right = new TreeNode(4);
    root4->left->left->left = new TreeNode(1);
    test(root4, 3, 3);

    TreeNode* root5 = new TreeNode(1);
    root5->right = new TreeNode(2);
    root5->right->right = new TreeNode(3);
    root5->right->right->right = new TreeNode(4);
    test(root5, 4, 4);

    return 0;
}
