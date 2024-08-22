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


TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if(!root1 && !root2) {
        return nullptr;
    } else if(!root1) {
        return root2;
    } else if(!root2) {
        return root1;
    }

    return new TreeNode(root1->val + root2->val, mergeTrees(root1->left, root2->left), mergeTrees(root1->right, root2->right));
}

void printTree(TreeNode* root) {
    if (!root) {
        cout << "null";
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        if (current) {
            cout << current->val << " ";
            q.push(current->left);
            q.push(current->right);
        } else {
            cout << "null ";
        }
    }
    cout << endl;
}

void runTestCase(TreeNode* root1, TreeNode* root2, TreeNode* expected) {
    cout << "Tree 1: ";
    printTree(root1);
    cout << "Tree 2: ";
    printTree(root2);

    TreeNode* result = mergeTrees(root1, root2);

    cout << "Expected: ";
    printTree(expected);

    cout << "Result: ";
    printTree(result);
    cout << endl;
}

int main() {
    cout << "Test Cases:\n";

    TreeNode* tree1_1 = new TreeNode(1, new TreeNode(3, new TreeNode(5), nullptr), new TreeNode(2));
    TreeNode* tree2_1 = new TreeNode(2, new TreeNode(1, nullptr, new TreeNode(4)), new TreeNode(3, nullptr, new TreeNode(7)));
    TreeNode* expected_1 = new TreeNode(3, new TreeNode(4, new TreeNode(5), new TreeNode(4)), new TreeNode(5, nullptr, new TreeNode(7)));
    runTestCase(tree1_1, tree2_1, expected_1);

    TreeNode* tree1_2 = new TreeNode(1);
    TreeNode* tree2_2 = new TreeNode(1, new TreeNode(2), nullptr);
    TreeNode* expected_2 = new TreeNode(2, new TreeNode(2), nullptr);
    runTestCase(tree1_2, tree2_2, expected_2);

    return 0;
}
