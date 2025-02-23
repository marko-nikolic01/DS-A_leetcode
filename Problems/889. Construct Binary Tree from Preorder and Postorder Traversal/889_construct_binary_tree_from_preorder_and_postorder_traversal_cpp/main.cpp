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

TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    TreeNode* tree = new TreeNode(preorder[0]);
    TreeNode* node;

    vector<TreeNode*> nodes = {tree};

    short iPostorder = 0;
    short n = preorder.size();
    for(short iPreorder = 1; iPreorder < n; ++iPreorder) {
        node = new TreeNode(preorder[iPreorder]);

        if(nodes.back()->left) {
            nodes.back()->right = node;
        } else {
            nodes.back()->left = node;
        }

        if(preorder[iPreorder] != postorder[iPostorder]) {
            nodes.push_back(node);
        } else {
            while(++iPostorder < n && nodes.back()->val == postorder[iPostorder]) {
                nodes.pop_back();
            }
        }
    }

    return tree;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
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

void test(vector<int> preorder, vector<int> postorder, TreeNode* expected) {
    cout << "Preorder traversal: ";
    printArray(preorder);

    cout << "Postorder traversal: ";
    printArray(postorder);

    cout << "Expected:";
    printTree(expected);

    cout << "Result:";
    printTree(constructFromPrePost(preorder, postorder));

    cout << endl;
}

int main() {
    vector<int> preorder1 = {1, 2, 4, 5, 3, 6, 7};
    vector<int> postorder1 = {4, 5, 2, 6, 7, 3, 1};
    TreeNode* expected1 = new TreeNode(1);
    expected1->left = new TreeNode(2);
    expected1->right = new TreeNode(3);
    expected1->left->left = new TreeNode(4);
    expected1->left->right = new TreeNode(5);
    expected1->right->left = new TreeNode(6);
    expected1->right->right = new TreeNode(7);
    test(preorder1, postorder1, expected1);

    vector<int> preorder2 = {1};
    vector<int> postorder2 = {1};
    TreeNode* expected2 = new TreeNode(1);
    test(preorder2, postorder2, expected2);

    vector<int> preorder3 = {1, 2, 3};
    vector<int> postorder3 = {3, 2, 1};
    TreeNode* expected3 = new TreeNode(1);
    expected3->left = new TreeNode(2);
    expected3->left->left = new TreeNode(3);
    test(preorder3, postorder3, expected3);

    vector<int> preorder4 = {3, 9, 20, 15, 7};
    vector<int> postorder4 = {9, 15, 7, 20, 3};
    TreeNode* expected4 = new TreeNode(3);
    expected4->left = new TreeNode(9);
    expected4->right = new TreeNode(20);
    expected4->right->left = new TreeNode(15);
    expected4->right->right = new TreeNode(7);
    test(preorder4, postorder4, expected4);

    vector<int> preorder5 = {1, 2, 3, 4, 5};
    vector<int> postorder5 = {5, 4, 3, 2, 1};
    TreeNode* expected5 = new TreeNode(1);
    expected5->left = new TreeNode(2);
    expected5->left->left = new TreeNode(3);
    expected5->left->left->left = new TreeNode(4);
    expected5->left->left->left->left = new TreeNode(5);
    test(preorder5, postorder5, expected5);

    return 0;
}
