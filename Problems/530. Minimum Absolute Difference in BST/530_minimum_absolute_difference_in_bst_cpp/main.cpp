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

void getMinimumDifference(TreeNode* root, int& min, int& max, int& diff) {
    if(diff == 0) {
        return;
    }

    int min1 = -1;
    int max1 = -1;

    if(root->left) {
        getMinimumDifference(root->left, min, max, diff);

        int difference = root->val - max;
        if(difference < diff || diff == -1) {
            diff = difference;
        }

        min1 = min;
    }

    if(root->right) {
        getMinimumDifference(root->right, min, max, diff);

        int difference = min -root->val;
        if(difference < diff || diff == -1) {
            diff = difference;
        }

        max1 = max;
    }

    min = min1 == -1 ? root->val : min1;
    max = max1 == -1 ? root->val : max1;
}

int getMinimumDifference(TreeNode* root) {
    int min;
    int max;
    int diff = -1;

    getMinimumDifference(root, min, max, diff);

    return diff;
}

void printTree(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node) {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        } else {
            cout << "null ";
        }
    }
    cout << endl;
}

void test() {
    TreeNode* root1 = new TreeNode(4);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(6);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(3);
    cout << "Tree 1: ";
    printTree(root1);
    int expected1 = 1;
    int result1 = getMinimumDifference(root1);
    cout << "Expected: " << expected1 << endl;
    cout << "Result: " << result1 << endl;
    cout << endl;

    TreeNode* root2 = new TreeNode(1);
    root2->right = new TreeNode(5);
    root2->right->left = new TreeNode(3);
    cout << "Tree 2: ";
    printTree(root2);
    int expected2 = 2;
    int result2 = getMinimumDifference(root2);
    cout << "Expected: " << expected2 << endl;
    cout << "Result: " << result2 << endl;
    cout << endl;

    TreeNode* root3 = new TreeNode(0);
    root3->right = new TreeNode(2236);
    root3->right->left = new TreeNode(1277);
    root3->right->right = new TreeNode(2776);
    root3->right->left->left = new TreeNode(519);
    cout << "Tree 3: ";
    printTree(root3);
    int expected3 = 519;
    int result3 = getMinimumDifference(root3);
    cout << "Expected: " << expected3 << endl;
    cout << "Result: " << result3 << endl;
    cout << endl;
}

int main() {
    test();
    return 0;
}
