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

int sumEvenGrandparent(TreeNode* root, bool isGrandparentEven, bool isParentEven) {
    int sum = isGrandparentEven ? root->val : 0;

    if(root->left) {
        sum += sumEvenGrandparent(root->left, isParentEven, root->val % 2 == 0);
    }

    if(root->right) {
        sum += sumEvenGrandparent(root->right, isParentEven, root->val % 2 == 0);
    }

    return sum;
}

int sumEvenGrandparent(TreeNode* root) {
    return sumEvenGrandparent(root, false, false);
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

void test(TreeNode* root, int expected) {
    cout << "Tree:";
    printTree(root);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << sumEvenGrandparent(root) << endl;

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(6);
    root1->left = new TreeNode(7);
    root1->right = new TreeNode(8);
    root1->left->left = new TreeNode(2);
    root1->left->right = new TreeNode(7);
    root1->right->left = new TreeNode(1);
    root1->right->right = new TreeNode(3);
    root1->left->left->left = new TreeNode(9);
    root1->right->right->right = new TreeNode(5);
    test(root1, 18);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->right->right = new TreeNode(5);
    test(root2, 0);

    TreeNode* root3 = new TreeNode(5);
    test(root3, 0);

    TreeNode* root4 = new TreeNode(1);
    test(root4, 0);

    TreeNode* root5 = new TreeNode(10);
    root5->left = new TreeNode(5);
    root5->right = new TreeNode(15);
    root5->left->left = new TreeNode(2);
    root5->left->right = new TreeNode(7);
    root5->right->left = new TreeNode(12);
    root5->right->right = new TreeNode(17);
    test(root5, 38);

    TreeNode* root6 = new TreeNode(4);
    root6->left = new TreeNode(3);
    root6->right = new TreeNode(8);
    root6->left->left = new TreeNode(2);
    root6->left->right = new TreeNode(1);
    root6->right->left = new TreeNode(5);
    root6->right->right = new TreeNode(9);
    test(root6, 17);

    TreeNode* root7 = new TreeNode(2);
    test(root7, 0);

    return 0;
}
