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

int sufficientSubset(TreeNode* root, int limit, int sum) {
    sum += root->val;

    if(root->left) {
        int maximumSum = limit - 1;

        int left = sufficientSubset(root->left, limit, sum);
        if(left < limit) {
            root->left = nullptr;
        }
        if(left > maximumSum) {
            maximumSum = left;
        }

        if(root->right) {
            left = sufficientSubset(root->right, limit, sum);
            if(left < limit) {
                root->right = nullptr;
            }
            if(left > maximumSum) {
                maximumSum = left;
            }
        }

        return maximumSum;
    } else if(root->right) {
        int maximumSum = limit - 1;

        int right = sufficientSubset(root->right, limit, sum);
        if(right < limit) {
            root->right = nullptr;
        }
        if(right > maximumSum) {
            maximumSum = right;
        }

        return maximumSum;
    }

    return sum;
}

TreeNode* sufficientSubset(TreeNode* root, int limit) {
    if(sufficientSubset(root, limit, 0) < limit) {
        return nullptr;
    }

    return root;
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

void test(TreeNode* root, int limit, TreeNode* expected) {
    cout << "Tree:";
    printTree(root);

    cout << "Limit: " << limit << endl;

    cout << "Expected:";
    printTree(expected);

    cout << "Result:";
    printTree(sufficientSubset(root, limit));

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(5);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    TreeNode* expected1 = new TreeNode(1);
    expected1->left = new TreeNode(2);
    expected1->right = new TreeNode(5);
    expected1->left->left = new TreeNode(3);
    expected1->left->right = new TreeNode(4);
    test(root1, 5, expected1);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(5);
    root2->left->left = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    TreeNode* expected2 = nullptr;
    test(root2, 10, expected2);

    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->left->left = new TreeNode(3);
    root3->left->right = new TreeNode(4);
    TreeNode* expected3 = new TreeNode(1);
    expected3->left = new TreeNode(2);
    expected3->left->right = new TreeNode(4);
    test(root3, 7, expected3);

    TreeNode* root4 = new TreeNode(1);
    root4->right = new TreeNode(2);
    root4->right->left = new TreeNode(3);
    root4->right->right = new TreeNode(1);
    TreeNode* expected4 = new TreeNode(1);
    expected4->right = new TreeNode(2);
    expected4->right->left = new TreeNode(3);
    test(root4, 5, expected4);

    TreeNode* root5 = new TreeNode(1);
    TreeNode* expected5 = new TreeNode(1);
    test(root5, 1, expected5);

    TreeNode* root6 = new TreeNode(1);
    TreeNode* expected6 = nullptr;
    test(root6, 2, expected6);


    return 0;
}
