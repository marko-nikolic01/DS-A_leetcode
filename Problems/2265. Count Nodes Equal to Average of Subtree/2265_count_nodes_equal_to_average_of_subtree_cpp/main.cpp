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

int averageOfSubtree(TreeNode* root, short& nodes, short& averageNodes) {
    ++nodes;

    short leftNodes = 0;
    short rightNodes = 0;

    int value = root->val;

    if(root->left) {
        value += averageOfSubtree(root->left, leftNodes, averageNodes);
    }

    if(root->right) {
        value += averageOfSubtree(root->right, rightNodes, averageNodes);
    }

    nodes += leftNodes + rightNodes;

    if(root->val == value / nodes) {
        ++averageNodes;
    }

    return value;
}

int averageOfSubtree(TreeNode* root) {
    short nodes = 0;
    short averageNodes = 0;

    averageOfSubtree(root, nodes, averageNodes);

    return averageNodes;
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

    cout << "Result: " << averageOfSubtree(root) << endl;

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(4);
    root1->left = new TreeNode(8);
    root1->right = new TreeNode(5);
    root1->left->left = new TreeNode(0);
    root1->left->right = new TreeNode(1);
    root1->right->right = new TreeNode(6);
    test(root1, 5);

    TreeNode* root2 = new TreeNode(1);
    test(root2, 1);

    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(3);
    root3->right = new TreeNode(2);
    test(root3, 2);

    TreeNode* root4 = new TreeNode(3);
    root4->left = new TreeNode(0);
    root4->right = new TreeNode(1);
    root4->left->left = new TreeNode(0);
    root4->right->right = new TreeNode(2);
    test(root4, 4);

    TreeNode* root5 = new TreeNode(6);
    root5->left = new TreeNode(3);
    root5->right = new TreeNode(7);
    root5->left->left = new TreeNode(2);
    root5->left->right = new TreeNode(4);
    root5->right->left = new TreeNode(5);
    root5->right->right = new TreeNode(8);
    test(root5, 5);

    TreeNode* root6 = new TreeNode(10);
    root6->left = new TreeNode(5);
    root6->right = new TreeNode(15);
    root6->left->left = new TreeNode(2);
    root6->left->right = new TreeNode(7);
    root6->right->left = new TreeNode(12);
    root6->right->right = new TreeNode(20);
    test(root6, 6);

    return 0;
}
