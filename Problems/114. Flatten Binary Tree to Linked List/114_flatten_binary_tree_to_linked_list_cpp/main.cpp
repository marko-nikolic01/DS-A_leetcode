#include <iostream>
#include <stack>
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

void flatten(TreeNode* root) {
    if(!root) {
        return;
    }

    stack<TreeNode*> nodes;
    nodes.push(root);

    while(!nodes.empty()) {
        TreeNode* node = nodes.top();
        nodes.pop();

        if(!node->left && !node->right && !nodes.empty()) {
            node->right = nodes.top();
            continue;
        }

        if(node->right) {
            nodes.push(node->right);
        }

        if(node->left) {
            node->right = node->left;
            nodes.push(node->left);
            node->left = nullptr;
        }
    }
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

void test(TreeNode* root, TreeNode* expected) {
    cout << "Tree:";
    printTree(root);

    cout << "Expected:";
    printTree(expected);

    flatten(root);
    cout << "Result:";
    printTree(root);

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(5);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    root1->right->right = new TreeNode(6);
    TreeNode* expected1 = new TreeNode(1);
    expected1->right= new TreeNode(2);
    expected1->right->right = new TreeNode(3);
    expected1->right->right->right = new TreeNode(4);
    expected1->right->right->right->right = new TreeNode(5);
    expected1->right->right->right->right->right = new TreeNode(6);
    test(root1, expected1);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->left->left = new TreeNode(3);
    root2->left->left->left = new TreeNode(4);
    TreeNode* expected2 = new TreeNode(1);
    expected2->right = new TreeNode(2);
    expected2->right->right = new TreeNode(3);
    expected2->right->right->right = new TreeNode(4);
    test(root2, expected2);

    TreeNode* root3 = new TreeNode(1);
    root3->right = new TreeNode(2);
    root3->right->right = new TreeNode(3);
    root3->right->right->right = new TreeNode(4);
    TreeNode* expected3 = new TreeNode(1);
    expected3->right = new TreeNode(2);
    expected3->right->right = new TreeNode(3);
    expected3->right->right->right = new TreeNode(4);
    test(root3, expected3);

    TreeNode* root4 = new TreeNode(1);
    TreeNode* expected4 = new TreeNode(1);
    test(root4, expected4);

    TreeNode* root5 = nullptr;
    TreeNode* expected5 = nullptr;
    test(root5, expected5);

    TreeNode* root6 = new TreeNode(1);
    root6->left = new TreeNode(2);
    root6->right = new TreeNode(5);
    root6->left->left = new TreeNode(3);
    root6->left->right = new TreeNode(4);
    root6->right->right = new TreeNode(6);
    root6->left->right->left = new TreeNode(7);
    root6->left->right->right = new TreeNode(8);
    TreeNode* expected6 = new TreeNode(1);
    expected6->right = new TreeNode(2);
    expected6->right->right = new TreeNode(3);
    expected6->right->right->right = new TreeNode(4);
    expected6->right->right->right->right = new TreeNode(7);
    expected6->right->right->right->right->right = new TreeNode(8);
    expected6->right->right->right->right->right->right = new TreeNode(5);
    expected6->right->right->right->right->right->right->right = new TreeNode(6);
    test(root6, expected6);

    TreeNode* root7 = new TreeNode(1);
    root7->right = new TreeNode(2);
    root7->right->right = new TreeNode(3);
    root7->right->right->right = new TreeNode(4);
    root7->right->right->right->right = new TreeNode(5);
    TreeNode* expected7 = new TreeNode(1);
    expected7->right = new TreeNode(2);
    expected7->right->right = new TreeNode(3);
    expected7->right->right->right = new TreeNode(4);
    expected7->right->right->right->right = new TreeNode(5);
    test(root7, expected7);

    return 0;
}
