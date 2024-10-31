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

int deepestLeavesSum(TreeNode* root) {
    queue<TreeNode*> level;
    level.push(root);

    int sum;

    while(!level.empty()) {
        sum = 0;

        for(int i = level.size(); i > 0; --i) {
            root = level.front();

            sum += root->val;

            if(root->left)  {
                level.push(root->left);
            }

            if(root->right)  {
                level.push(root->right);
            }

            level.pop();
        }
    }

    return sum;
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

    cout << "Result: " << deepestLeavesSum(root) << endl;

    cout << endl;
}


int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(5);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    test(root1, 7);

    TreeNode* root2 = new TreeNode(10);
    root2->left = new TreeNode(7);
    root2->right = new TreeNode(15);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(9);
    root2->right->right = new TreeNode(18);
    test(root2, 31);

    TreeNode* root3 = new TreeNode(5);
    root3->left = new TreeNode(3);
    root3->right = new TreeNode(8);
    root3->left->left = new TreeNode(2);
    root3->left->left->left = new TreeNode(1);
    test(root3, 1);

    TreeNode* root4 = new TreeNode(6);
    root4->left = new TreeNode(4);
    root4->right = new TreeNode(7);
    root4->left->left = new TreeNode(2);
    root4->left->right = new TreeNode(5);
    root4->right->right = new TreeNode(9);
    root4->right->right->left = new TreeNode(8);
    test(root4, 8);

    TreeNode* root5 = new TreeNode(1);
    root5->left = new TreeNode(2);
    root5->right = new TreeNode(3);
    root5->left->left = new TreeNode(4);
    root5->left->right = new TreeNode(5);
    root5->right->right = new TreeNode(6);
    root5->left->left->left = new TreeNode(7);
    root5->left->left->right = new TreeNode(8);
    test(root5, 15);

    TreeNode* root6 = new TreeNode(10);
    root6->left = new TreeNode(8);
    root6->right = new TreeNode(12);
    root6->left->left = new TreeNode(6);
    root6->left->left->left = new TreeNode(5);
    root6->right->right = new TreeNode(14);
    root6->right->right->right = new TreeNode(15);
    test(root6, 20);

    TreeNode* root7 = new TreeNode(1);
    root7->left = new TreeNode(2);
    root7->right = new TreeNode(3);
    test(root7, 5);

    TreeNode* root8 = new TreeNode(1);
    root8->left = new TreeNode(2);
    test(root8, 2);

    TreeNode* root9 = new TreeNode(1);
    test(root9, 1);

    return 0;
}
