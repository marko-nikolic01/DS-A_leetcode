#include <iostream>
#include <vector>
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

void rightSideView(TreeNode* root, vector<int>& view, int& maxDepth, int depth) {
    if(!root) {
        return;
    }

    if(++depth > maxDepth) {
        view.push_back(root->val);
        maxDepth = depth;
    }

    rightSideView(root->right, view, maxDepth, depth);
    rightSideView(root->left, view, maxDepth, depth);
}

vector<int> rightSideView(TreeNode* root) {
    if(!root) {
        return {};
    }

    vector<int> view;

    int maxDepth = 0;

    rightSideView(root, view, maxDepth, 0);

    return view;
}

void printTree(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
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
}

void printResult(TreeNode* root, const vector<int>& expected) {
    cout << "Tree:" << endl;
    printTree(root);

    cout << "Expected: ";
    for (int val : expected) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Result: ";
    for (int val : rightSideView(root)) {
        cout << val << " ";
    }
    cout << endl;


    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->right = new TreeNode(5);
    root1->right->right = new TreeNode(4);
    printResult(root1, {1, 3, 4});

    TreeNode* root2 = new TreeNode(1);
    root2->right = new TreeNode(3);
    printResult(root2, {1, 3});

    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->left->left = new TreeNode(4);
    printResult(root3, {1, 2, 4});

    printResult(nullptr, {});

    return 0;
}
