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

short minCameraCover(TreeNode* root, short& cameras) {
    bool hasCamera = false;
    bool isCoveredByCamera = false;

    if(root->left) {
        short left = minCameraCover(root->left, cameras);
        if(left < 0) {
            hasCamera = true;
        } else if(left > 0) {
            isCoveredByCamera = true;
        }
    }

    if(root->right) {
        short right = minCameraCover(root->right, cameras);
        if(right < 0) {
            hasCamera = true;
        } else if(right > 0) {
            isCoveredByCamera = true;
        }
    }

    if(hasCamera) {
        ++cameras;
        return 1;
    }

    return isCoveredByCamera ? 0 : -1;
}

int minCameraCover(TreeNode* root) {
    short cameras = 0;

    if(minCameraCover(root, cameras) < 0) {
        ++cameras;
    }

    return cameras;
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

    cout << "Result: " << minCameraCover(root) << endl;

    cout << endl;
}

int main() {
    TreeNode* test1 = new TreeNode(0);
    test1->left = new TreeNode(0);
    test1->left->right = new TreeNode(0);
    test1->left->right->left = new TreeNode(0);
    test1->left->right->right = new TreeNode(0);
    test(test1, 2);

    TreeNode* test2 = new TreeNode(0);
    test2->left = new TreeNode(0);
    test2->left->right = new TreeNode(0);
    test2->left->right->right = new TreeNode(0);
    test2->left->right->right->right = new TreeNode(0);
    test(test2, 2);

    TreeNode* test3 = new TreeNode(0);
    test(test3, 1);

    TreeNode* test4 = new TreeNode(0);
    test4->left = new TreeNode(0);
    test4->right = new TreeNode(0);
    test4->left->left = new TreeNode(0);
    test4->left->right = new TreeNode(0);
    test4->right->left = new TreeNode(0);
    test4->right->right = new TreeNode(0);
    test(test4, 2);

    TreeNode* test5 = new TreeNode(0);
    test5->left = new TreeNode(0);
    test5->right = new TreeNode(0);
    test5->right->right = new TreeNode(0);
    test(test5, 2);

    return 0;
}
