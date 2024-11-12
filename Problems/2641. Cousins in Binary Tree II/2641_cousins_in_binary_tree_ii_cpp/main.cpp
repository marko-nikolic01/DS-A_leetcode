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

TreeNode* replaceValueInTree(TreeNode* root) {
    queue<TreeNode*> level;
    level.push(root);

    root->val = 0;

    while(!level.empty()) {
        int levelSum = 0;

        for(int i = level.size(); i > 0; --i) {
            if(level.front()->left) {
                levelSum += level.front()->left->val;
            }

            if(level.front()->right) {
                levelSum += level.front()->right->val;
            }

            level.push(level.front());
            level.pop();
        }

        for(int i = level.size(); i > 0; --i) {
            if(level.front()->left) {
                level.push(level.front()->left);
                if(level.front()->right) {
                    level.push(level.front()->right);
                    level.front()->left->val = levelSum - level.front()->left->val - level.front()->right->val;
                    level.front()->right->val = level.front()->left->val;
                } else {
                    level.front()->left->val = levelSum - level.front()->left->val;
                }
            } else if(level.front()->right) {
                level.push(level.front()->right);
                level.front()->right->val = levelSum - level.front()->right->val;
            }

            level.pop();
        }
    }

    return root;
}

void printTree(TreeNode* root) {
    if (!root) {
        cout << endl;;
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
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
    cout << "Tree:";
    printTree(root);

    cout << "Expected:";
    printTree(expected);

    cout << "Result:";
    printTree(replaceValueInTree(root));

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    TreeNode* expected1 = new TreeNode(0);
    expected1->left = new TreeNode(0);
    expected1->right = new TreeNode(0);
    test(root1, expected1);

    TreeNode* root2 = new TreeNode(4);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(5);
    root2->left->left = new TreeNode(1);
    root2->left->right = new TreeNode(3);
    TreeNode* expected2 = new TreeNode(0);
    expected2->left = new TreeNode(0);
    expected2->right = new TreeNode(0);
    expected2->left->left = new TreeNode(0);
    expected2->left->right = new TreeNode(0);
    test(root2, expected2);

    TreeNode* root3 = new TreeNode(10);
    root3->left = new TreeNode(5);
    root3->right = new TreeNode(15);
    root3->left->left = new TreeNode(3);
    root3->left->right = new TreeNode(7);
    root3->right->right = new TreeNode(18);
    TreeNode* expected3 = new TreeNode(0);
    expected3->left = new TreeNode(0);
    expected3->right = new TreeNode(0);
    expected3->left->left = new TreeNode(18);
    expected3->left->right = new TreeNode(18);
    expected3->right->right = new TreeNode(10);
    test(root3, expected3);

    TreeNode* root4 = new TreeNode(7);
    root4->left = new TreeNode(3);
    root4->right = new TreeNode(8);
    root4->left->left = new TreeNode(1);
    root4->left->right = new TreeNode(5);
    root4->right->left = new TreeNode(6);
    root4->right->right = new TreeNode(10);
    TreeNode* expected4 = new TreeNode(0);
    expected4->left = new TreeNode(0);
    expected4->right = new TreeNode(0);
    expected4->left->left = new TreeNode(16);
    expected4->left->right = new TreeNode(16);
    expected4->right->left = new TreeNode(6);
    expected4->right->right = new TreeNode(6);
    test(root4, expected4);

    TreeNode* root5 = new TreeNode(12);
    root5->left = new TreeNode(7);
    root5->right = new TreeNode(13);
    root5->left->left = new TreeNode(4);
    root5->left->right = new TreeNode(9);
    root5->right->left = new TreeNode(10);
    root5->right->right = new TreeNode(15);
    TreeNode* expected5 = new TreeNode(0);
    expected5->left = new TreeNode(0);
    expected5->right = new TreeNode(0);
    expected5->left->left = new TreeNode(25);
    expected5->left->right = new TreeNode(25);
    expected5->right->left = new TreeNode(13);
    expected5->right->right = new TreeNode(13);
    test(root5, expected5);

    TreeNode* root6 = new TreeNode(5);
    root6->left = new TreeNode(3);
    root6->right = new TreeNode(6);
    root6->left->left = new TreeNode(2);
    root6->left->right = new TreeNode(4);
    root6->right->left = new TreeNode(1);
    root6->right->right = new TreeNode(7);
    TreeNode* expected6 = new TreeNode(0);
    expected6->left = new TreeNode(0);
    expected6->right = new TreeNode(0);
    expected6->left->left = new TreeNode(8);
    expected6->left->right = new TreeNode(8);
    expected6->right->left = new TreeNode(6);
    expected6->right->right = new TreeNode(6);
    test(root6, expected6);

    return 0;
}
