#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int distanceK(TreeNode* root, int target, int k, vector<int>& values) {
    if(target == -1) {
        if(--k == 0) {
            values.push_back(root->val);
        } else {
            if(root->left) {
                distanceK(root->left, -1, k, values);
            }

            if(root->right) {
                distanceK(root->right, -1, k, values);
            }
        }
    } else if(root->val == target) {
        if(root->left) {
            distanceK(root->left, -1, k, values);
        }

        if(root->right) {
            distanceK(root->right, -1, k, values);
        }

        return k;
    } else {
        if(root->left) {
            int kDepth = distanceK(root->left, target, k, values);
            if(--kDepth == 0) {
                values.push_back(root->val);
                return 0;
            } else if(kDepth > 0) {
                if(root->right) {
                    distanceK(root->right, -1, kDepth, values);
                }
                return kDepth;
            }
        }

        if(root->right) {
            int kDepth = distanceK(root->right, target, k, values);
            if(--kDepth == 0) {
                values.push_back(root->val);
            } else if(kDepth > 0) {
                if(root->left) {
                    distanceK(root->left, -1, kDepth, values);
                }
                return kDepth;
            }
        }
    }

    return 0;
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    if(k == 0) {
        return {target->val};
    }

    vector<int> values;

    distanceK(root, target->val, k, values);

    return values;
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

void test(TreeNode* root, TreeNode* target, int k, vector<int> expected) {
    cout << "Tree:";
    printTree(root);

    cout << "Target: " << target->val << endl;

    cout << "k: " << k << endl;

    cout << "Expected: ";
    for (int e : expected) {
        cout << e << " ";
    }
    cout << endl;

    cout << "Result:   ";
    for (int result : distanceK(root, target, k)) {
        cout << result << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(1);
    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(2);
    root1->left->right->left = new TreeNode(7);
    root1->left->right->right = new TreeNode(4);
    root1->right->left = new TreeNode(0);
    root1->right->right = new TreeNode(8);
    test(root1, root1->left, 2, {7, 4, 1});

    TreeNode* root2 = new TreeNode(1);
    test(root2, root2, 3, {});

    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(3);
    root3->left->left = new TreeNode(4);
    root3->left->right = new TreeNode(5);
    test(root3, root3->left, 1, {4, 5, 1});

    test(root3, root3->left, 2, {3});

    test(root1, root1, 1, {5, 1});

    TreeNode* root4 = new TreeNode(1);
    root4->left = new TreeNode(2);
    test(root4, root4->left, 1, {1});

    test(root1, root1->right->right, 0, {8});

    return 0;
}
