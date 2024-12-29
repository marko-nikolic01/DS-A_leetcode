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

int maxPathSum(TreeNode* root, int& maxSum) {
    int left = root->left ? maxPathSum(root->left, maxSum) : 0;
    int right = root->right ? maxPathSum(root->right, maxSum) : 0;

    if(root->val < 0) {
        if(left > 0) {
            if(right > 0) {
                if(root->val + left + right > maxSum) {
                    maxSum = root->val + left + right;
                }

                if(left > right) {
                    return -root->val < left ? root->val + left : 0;
                }
                return -root->val < right ? root->val + right : 0;
            }else if(root->val + left > maxSum) {
                maxSum = root->val + left;
            }
            return -root->val < left ? root->val + left : 0;
        } else if(right > 0) {
            if(root->val + right > maxSum) {
                maxSum = root->val + right;
            }
            return -root->val < right ? root->val + right : 0;
        } else if(root->val > maxSum) {
            maxSum = root->val;
        }
        return 0;
    } if(left > 0) {
        if(right > 0) {
            if(root->val + left + right > maxSum) {
                maxSum = root->val + left + right;
            }
            return left > right ? root->val + left : root->val + right;
        }else if(root->val + left > maxSum) {
            maxSum = root->val + left;
        }
        return root->val + left;
    } else if(right > 0) {
        if(root->val + right > maxSum) {
            maxSum = root->val + right;
        }
        return root->val + right;
    } else if(root->val > maxSum) {
        maxSum = root->val;
    }
    return root->val;
}

int maxPathSum(TreeNode* root) {
    int maxSum = -1000;

    maxPathSum(root, maxSum);

    return maxSum;
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

void test(TreeNode* root, int expected) {
    cout << "Tree: ";
    printTree(root);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxPathSum(root) << endl;

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    test(root1, 6);

    TreeNode* root2 = new TreeNode(-10);
    root2->left = new TreeNode(9);
    root2->right = new TreeNode(20);
    root2->right->left = new TreeNode(15);
    root2->right->right = new TreeNode(7);
    test(root2, 42);

    TreeNode* root3 = new TreeNode(-1);
    root3->left = new TreeNode(-2);
    root3->right = new TreeNode(-3);
    test(root3, -1);

    TreeNode* root4 = new TreeNode(5);
    root4->left = new TreeNode(-2);
    root4->right = new TreeNode(3);
    test(root4, 8);

    TreeNode* root5 = new TreeNode(1);
    root5->left = new TreeNode(-2);
    root5->right = new TreeNode(-3);
    root5->left->left = new TreeNode(4);
    root5->left->right = new TreeNode(-5);
    root5->right->left = new TreeNode(-6);
    root5->right->right = new TreeNode(10);
    test(root5, 10);

    TreeNode* root6 = new TreeNode(1);
    root6->left = new TreeNode(2);
    root6->right = new TreeNode(3);
    root6->left->left = new TreeNode(4);
    root6->left->right = new TreeNode(5);
    test(root6, 11);

    TreeNode* root7 = new TreeNode(1);
    root7->left = new TreeNode(-2);
    root7->right = new TreeNode(3);
    root7->left->left = new TreeNode(-4);
    root7->left->right = new TreeNode(5);
    root7->right->left = new TreeNode(-6);
    root7->right->right = new TreeNode(7);
    test(root7, 14);

    TreeNode* root8 = new TreeNode(0);
    test(root8, 0);

    TreeNode* root9 = new TreeNode(1000);
    root9->left = new TreeNode(-1000);
    root9->right = new TreeNode(-1000);
    test(root9, 1000);

    TreeNode* root10 = new TreeNode(1000);
    root10->left = new TreeNode(-1000);
    root10->right = new TreeNode(1000);
    test(root10, 2000);

    return 0;
}
