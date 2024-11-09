#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* reverseOddLevels(TreeNode* root) {
    queue<TreeNode*> level;
    level.push(root);

    stack<int> reverseLevel;

    bool reverse = false;

    while(!level.empty()) {
        if(reverse) {
            for(int i = level.size(); i > 0; --i) {
                level.front()->val = reverseLevel.top();

                if(level.front()->left) {
                    level.push(level.front()->left);
                }

                if(level.front()->right) {
                    level.push(level.front()->right);
                }

                level.pop();
                reverseLevel.pop();
            }
        } else {
            for(int i = level.size(); i > 0; --i) {
                if(level.front()->left) {
                    level.push(level.front()->left);
                    reverseLevel.push(level.front()->left->val);
                }

                if(level.front()->right) {
                    level.push(level.front()->right);
                    reverseLevel.push(level.front()->right->val);
                }

                level.pop();
            }
        }

        reverse = !reverse;
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

    cout << "Expected";
    printTree(expected);

    cout << "Result:";
    printTree(reverseOddLevels(root));

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    TreeNode* expected1 = new TreeNode(1);
    expected1->left = new TreeNode(3);
    expected1->right = new TreeNode(2);
    test(root1, expected1);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);
    TreeNode* expected2 = new TreeNode(1);
    expected2->left = new TreeNode(3);
    expected2->right = new TreeNode(2);
    expected2->left->left = new TreeNode(4);
    expected2->left->right = new TreeNode(5);
    test(root2, expected2);

    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(3);
    root3->left->left = new TreeNode(4);
    root3->left->right = new TreeNode(5);
    root3->right->left = new TreeNode(6);
    root3->right->right = new TreeNode(7);
    TreeNode* expected3 = new TreeNode(1);
    expected3->left = new TreeNode(3);
    expected3->right = new TreeNode(2);
    expected3->left->left = new TreeNode(4);
    expected3->left->right = new TreeNode(5);
    expected3->right->left = new TreeNode(6);
    expected3->right->right = new TreeNode(7);
    test(root3, expected3);

    TreeNode* root4 = new TreeNode(1);
    root4->left = new TreeNode(2);
    root4->right = new TreeNode(3);
    root4->left->left = new TreeNode(4);
    root4->left->right = new TreeNode(5);
    root4->right->left = new TreeNode(6);
    root4->right->right = new TreeNode(7);
    root4->left->left->left = new TreeNode(8);
    root4->left->left->right = new TreeNode(9);
    TreeNode* expected4 = new TreeNode(1);
    expected4->left = new TreeNode(3);
    expected4->right = new TreeNode(2);
    expected4->left->left = new TreeNode(4);
    expected4->left->right = new TreeNode(5);
    expected4->right->left = new TreeNode(6);
    expected4->right->right = new TreeNode(7);
    expected4->left->left->left = new TreeNode(9);
    expected4->left->left->right = new TreeNode(8);
    test(root4, expected4);

    TreeNode* root5 = new TreeNode(1);
    root5->left = new TreeNode(2);
    root5->right = new TreeNode(3);
    root5->left->left = new TreeNode(4);
    root5->left->right = new TreeNode(5);
    root5->right->left = new TreeNode(6);
    root5->right->right = new TreeNode(7);
    root5->left->left->left = new TreeNode(8);
    root5->left->left->right = new TreeNode(9);
    root5->left->right->left = new TreeNode(10);
    root5->left->right->right = new TreeNode(11);
    TreeNode* expected5 = new TreeNode(1);
    expected5->left = new TreeNode(3);
    expected5->right = new TreeNode(2);
    expected5->left->left = new TreeNode(4);
    expected5->left->right = new TreeNode(5);
    expected5->right->left = new TreeNode(6);
    expected5->right->right = new TreeNode(7);
    expected5->left->left->left = new TreeNode(11);
    expected5->left->left->right = new TreeNode(10);
    expected5->left->right->left = new TreeNode(9);
    expected5->left->right->right = new TreeNode(8);
    test(root5, expected5);

    return 0;
}
