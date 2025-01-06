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

void tree2str(TreeNode* root, string& treeString) {
    treeString.append(to_string(root->val));

    if(root->left) {
        treeString.push_back('(');
        tree2str(root->left, treeString);
        treeString.push_back(')');

        if(root->right) {
            treeString.push_back('(');
            tree2str(root->right, treeString);
            treeString.push_back(')');
        }
    } else if(root->right) {
        treeString.push_back('(');
        treeString.push_back(')');

        treeString.push_back('(');
        tree2str(root->right, treeString);
        treeString.push_back(')');
    }
}

string tree2str(TreeNode* root) {
    string treeString = "";

    tree2str(root, treeString);

    return treeString;
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

void test(TreeNode* root, string expected) {
    cout << "Tree: ";
    printTree(root);

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << tree2str(root) << "\"" << endl;

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2, new TreeNode(4), nullptr);
    root1->right = new TreeNode(3);
    test(root1, "1(2(4))(3)");

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2, nullptr, new TreeNode(4));
    root2->right = new TreeNode(3);
    test(root2, "1(2()(4))(3)");

    TreeNode* root3 = new TreeNode(1);
    test(root3, "1");

    TreeNode* root4 = new TreeNode(1);
    root4->left = new TreeNode(2);
    root4->right = new TreeNode(3, nullptr, new TreeNode(5));
    test(root4, "1(2)(3()(5))");

    TreeNode* root5 = new TreeNode(1);
    root5->left = new TreeNode(2, new TreeNode(4), new TreeNode(5));
    root5->right = new TreeNode(3, new TreeNode(6), new TreeNode(7));
    test(root5, "1(2(4)(5))(3(6)(7))");

    TreeNode* root6 = new TreeNode(1);
    root6->right = new TreeNode(2, nullptr, new TreeNode(3));
    test(root6, "1()(2()(3))");

    TreeNode* root7 = new TreeNode(1);
    root7->left = new TreeNode(2, new TreeNode(4), new TreeNode(5, nullptr, new TreeNode(8)));
    root7->right = new TreeNode(3, new TreeNode(6), new TreeNode(7));
    test(root7, "1(2(4)(5()(8)))(3(6)(7))");

    return 0;
}
