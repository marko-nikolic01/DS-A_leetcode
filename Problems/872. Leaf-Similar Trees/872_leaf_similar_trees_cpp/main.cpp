#include <iostream>
#include <vector>
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

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> leaves;

    stack<TreeNode*> nodes;
    nodes.push(root1);

    while(!nodes.empty()) {
        root1 = nodes.top();
        nodes.pop();

        if(root1->left) {
            if(root1->right) {
                nodes.push(root1->right);
            }

            nodes.push(root1->left);
        } else if(root1->right) {
            nodes.push(root1->right);
        } else {
            leaves.push_back(root1->val);
        }
    }

    nodes.push(root2);

    while(!nodes.empty()) {
        root2 = nodes.top();
        nodes.pop();

        if(root2->right) {
            if(root2->left) {
                nodes.push(root2->left);
            }

            nodes.push(root2->right);
        } else if(root2->left) {
            nodes.push(root2->left);
        } else if(leaves.size() > 0 && root2->val == leaves.back()){
            leaves.pop_back();
        } else {
            return false;
        }
    }

    return leaves.size() == 0;
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

void test(TreeNode* root1, TreeNode* root2, bool expected) {
    cout << "Tree 1: ";
    printTree(root1);

    cout << "Tree 2: ";
    printTree(root2);

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (leafSimilar(root1, root2) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(1);
    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(2);
    root1->right->left = new TreeNode(9);
    root1->right->right = new TreeNode(8);
    root1->left->right->left = new TreeNode(7);
    root1->left->right->right = new TreeNode(4);
    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(1);
    root2->left->left = new TreeNode(6);
    root2->left->right = new TreeNode(7);
    root2->right->left = new TreeNode(4);
    root2->right->right = new TreeNode(2);
    root2->right->right->left = new TreeNode(9);
    root2->right->right->right = new TreeNode(8);
    test(root1, root2, true);

    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(3);
    root3->left->left = new TreeNode(4);
    root3->left->right = new TreeNode(5);
    TreeNode* root4 = new TreeNode(1);
    root4->left = new TreeNode(2);
    root4->right = new TreeNode(3);
    root4->left->left = new TreeNode(4);
    root4->left->right = new TreeNode(5);
    test(root3, root4, true);

    TreeNode* root5 = new TreeNode(3);
    root5->left = new TreeNode(5);
    root5->right = new TreeNode(1);
    root5->left->left = new TreeNode(6);
    root5->left->right = new TreeNode(2);
    root5->left->right->left = new TreeNode(7);
    TreeNode* root6 = new TreeNode(3);
    root6->left = new TreeNode(5);
    root6->right = new TreeNode(1);
    root6->left->left = new TreeNode(6);
    root6->left->right = new TreeNode(2);
    root6->left->right->left = new TreeNode(8);
    test(root5, root6, false);

    TreeNode* root7 = new TreeNode(2);
    root7->left = new TreeNode(1);
    root7->right = new TreeNode(3);
    TreeNode* root8 = new TreeNode(2);
    root8->left = new TreeNode(1);
    root8->right = new TreeNode(3);
    test(root7, root8, true);

    TreeNode* root9 = new TreeNode(4);
    root9->left = new TreeNode(1);
    root9->right = new TreeNode(5);
    root9->right->left = new TreeNode(2);
    root9->right->right = new TreeNode(3);
    TreeNode* root10 = new TreeNode(4);
    root10->left = new TreeNode(1);
    root10->right = new TreeNode(5);
    root10->right->left = new TreeNode(3);
    root10->right->right = new TreeNode(2);
    test(root9, root10, false);

    TreeNode* root11 = new TreeNode(10);
    root11->left = new TreeNode(5);
    root11->right = new TreeNode(15);
    root11->left->left = new TreeNode(3);
    root11->left->right = new TreeNode(7);
    TreeNode* root12 = new TreeNode(10);
    root12->left = new TreeNode(5);
    root12->right = new TreeNode(15);
    root12->left->left = new TreeNode(3);
    root12->left->right = new TreeNode(7);
    test(root11, root12, true);

    return 0;
}
