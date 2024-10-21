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

int maxLevelSum(TreeNode* root) {
    queue<TreeNode*> level;
    if(root->left) {
        level.push(root->left);
    }
    if(root->right) {
        level.push(root->right);
    }

    int maximumLevelSum = root->val;
    int maximumLevel = 1;
    int currentLevel = 1;

    while(!level.empty()) {
        currentLevel++;

        int levelSum = 0;

        for(int i = level.size(); i > 0; --i) {
            levelSum += level.front()->val;

            if(level.front()->left) {
                level.push(level.front()->left);
            }
            if(level.front()->right) {
                level.push(level.front()->right);
            }

            level.pop();
        }

        if(levelSum > maximumLevelSum) {
            maximumLevelSum = levelSum;
            maximumLevel = currentLevel;
        }
    }

    return maximumLevel;
}

void printTree(TreeNode* root) {
    if (!root) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();
            cout << node->val << " ";

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl;
    }
}

void test(TreeNode* root, int expected) {
    cout << "Tree:" << endl;
    printTree(root);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxLevelSum(root) << endl;

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    test(root1, 2);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);
    test(root2, 3);

    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(3);
    root3->right->right = new TreeNode(4);
    test(root3, 2);

    TreeNode* root4 = new TreeNode(1);
    root4->left = new TreeNode(2);
    root4->right = new TreeNode(3);
    root4->left->left = new TreeNode(4);
    root4->left->right = new TreeNode(5);
    root4->left->right->right = new TreeNode(6);
    test(root4, 3);

    TreeNode* root5 = new TreeNode(-1);
    root5->left = new TreeNode(-2);
    root5->right = new TreeNode(-3);
    root5->right->left = new TreeNode(-4);
    root5->right->right = new TreeNode(-5);
    test(root5, 1);

    TreeNode* root6= new TreeNode(0);
    test(root6, 1);

    return 0;
}
