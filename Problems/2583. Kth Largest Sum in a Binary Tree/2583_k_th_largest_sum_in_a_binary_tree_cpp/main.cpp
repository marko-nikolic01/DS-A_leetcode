#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

long long kthLargestLevelSum(TreeNode* root, int k) {
    vector<long long> sums;

    queue<TreeNode*> level;
    level.push(root);

    while(!level.empty()) {
        long long sum = 0;

        for(int i = level.size(); i > 0; --i) {
            sum += level.front()->val;

            if(level.front()->left) {
                level.push(level.front()->left);
            }

            if(level.front()->right) {
                level.push(level.front()->right);
            }

            level.pop();
        }

        sums.push_back(sum);
    }

    if(sums.size() < k) {
        return -1;
    }

    sort(sums.begin(), sums.end(), greater<long long>());

    return sums[--k];
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

void test(TreeNode* root, int k, long long expected) {
    cout << "Tree:";
    printTree(root);

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << kthLargestLevelSum(root, k) << endl;

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    test(root1, 1, 5);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);
    root2->right->left = new TreeNode(6);
    root2->right->right = new TreeNode(7);
    test(root2, 2, 5);

    TreeNode* root3 = new TreeNode(10);
    root3->left = new TreeNode(5);
    root3->right = new TreeNode(15);
    root3->left->left = new TreeNode(3);
    root3->left->right = new TreeNode(7);
    root3->right->left = new TreeNode(12);
    root3->right->right = new TreeNode(18);
    test(root3, 1, 40);

    TreeNode* root4 = new TreeNode(1);
    root4->left = new TreeNode(10);
    root4->right = new TreeNode(10);
    test(root4, 1, 20);

    TreeNode* root5 = new TreeNode(1);
    root5->left = new TreeNode(2);
    root5->right = new TreeNode(3);
    root5->left->left = new TreeNode(4);
    root5->right->right = new TreeNode(5);
    test(root5, 2, 5);

    TreeNode* root6 = new TreeNode(7);
    root6->left = new TreeNode(3);
    root6->right = new TreeNode(8);
    root6->left->left = new TreeNode(1);
    root6->left->right = new TreeNode(6);
    root6->right->right = new TreeNode(4);
    test(root6, 3, 7);

    TreeNode* root7 = new TreeNode(1);
    root7->left = new TreeNode(2);
    test(root7, 1, 2);

    TreeNode* root8 = new TreeNode(1);
    root8->left = new TreeNode(2);
    test(root8, 2, 1);

    TreeNode* root9 = new TreeNode(1);
    root9->left = new TreeNode(2);
    test(root9, 3, -1);

    return 0;
}
