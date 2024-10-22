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

bool isEvenOddTree(TreeNode* root) {
    bool isOdd = true;

    queue<TreeNode*> level;
    level.push(root);

    while(!level.empty()) {
        if(isOdd) {
            int last = 0;

            for(int i = level.size(); i > 0; --i) {
                if(level.front()->val % 2 == 0 || last >= level.front()->val) {
                    return false;
                }

                if(level.front()->left) {
                    level.push(level.front()->left);
                }

                if(level.front()->right) {
                    level.push(level.front()->right);
                }

                last = level.front()->val;

                level.pop();
            }

            isOdd = false;
        } else {
            int last = 1000001;

            for(int i = level.size(); i > 0; --i) {
                if(level.front()->val % 2 == 1 || last <= level.front()->val) {
                    return false;
                }

                if(level.front()->left) {
                    level.push(level.front()->left);
                }

                if(level.front()->right) {
                    level.push(level.front()->right);
                }

                last = level.front()->val;

                level.pop();
            }

            isOdd = true;
        }
    }

    return true;
}

void printTree(TreeNode* root) {
    if (!root) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();
            cout << node->val << " ";

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl;
    }
}

void test(TreeNode* root, bool expected) {
    cout << "Tree:" << endl;
    printTree(root);

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (isEvenOddTree(root) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(10);
    root1->right = new TreeNode(4);
    root1->left->left = new TreeNode(3);
    root1->right->right = new TreeNode(7);
    test(root1, true);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(10);
    root2->right = new TreeNode(4);
    root2->left->left = new TreeNode(9);
    root2->right->right = new TreeNode(3);
    test(root2, false);

    TreeNode* root3 = new TreeNode(1);
    test(root3, true);

    TreeNode* root4 = new TreeNode(1);
    root4->left = new TreeNode(10);
    root4->left->left = new TreeNode(2);
    test(root4, false);

    TreeNode* root5 = new TreeNode(1);
    root5->left = new TreeNode(10);
    root5->right = new TreeNode(4);
    root5->left->left = new TreeNode(3);
    root5->left->right = new TreeNode(3);
    root5->right->right = new TreeNode(9);
    test(root5, false);

    return 0;
}
