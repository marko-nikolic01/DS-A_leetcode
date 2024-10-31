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

void getAllElements(TreeNode* root, vector<int>& traversal) {
    if(root->left) {
        getAllElements(root->left, traversal);
    }

    traversal.push_back(root->val);

    if(root->right) {
        getAllElements(root->right, traversal);
    }
}

vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    vector<int> elements1;
    if(root1) {
        getAllElements(root1, elements1);
    }

    vector<int> elements2;
    if(root2) {
        getAllElements(root2, elements2);
    }

    int n1 = elements1.size();
    int n2 = elements2.size();

    int i = n1-- + n2--;
    vector<int> elements(i--);

    while(n1 > -1 && n2 > -1) {
        if(elements1[n1] > elements2[n2]) {
            elements[i--] = elements1[n1--];
        } else {
            elements[i--] = elements2[n2--];
        }
    }

    while(n1 > -1) {
        elements[i--] = elements1[n1--];
    }

    while(n2 > -1) {
        elements[i--] = elements2[n2--];
    }

    return elements;
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

void runTest(TreeNode* root1, TreeNode* root2, vector<int> expected) {
    cout << "Tree 1:";
    printTree(root1);

    cout << "Tree 2:";
    printTree(root2);

    cout << "Expected: ";
    for (int val : expected) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Result: ";
    for (int val : getAllElements(root1, root2)) {
        cout << val << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    TreeNode* root1 = new TreeNode(2, new TreeNode(1), new TreeNode(4));
    TreeNode* root2 = new TreeNode(1, nullptr, new TreeNode(3));
    runTest(root1, root2, {1, 1, 2, 3, 4});

    TreeNode* root3 = new TreeNode(5, new TreeNode(3, new TreeNode(2), new TreeNode(4)), new TreeNode(8));
    TreeNode* root4 = new TreeNode(7, new TreeNode(6), new TreeNode(9));
    runTest(root3, root4, {2, 3, 4, 5, 6, 7, 8, 9});

    TreeNode* root5 = new TreeNode(1);
    TreeNode* root6 = new TreeNode(2);
    runTest(root5, root6, {1, 2});

    TreeNode* root7 = new TreeNode(3, new TreeNode(1, nullptr, new TreeNode(2)), new TreeNode(4));
    TreeNode* root8 = new TreeNode(7, new TreeNode(6), nullptr);
    runTest(root7, root8, {1, 2, 3, 4, 6, 7});

    TreeNode* root9 = new TreeNode(10, new TreeNode(8, new TreeNode(7), nullptr), new TreeNode(15));
    TreeNode* root10 = new TreeNode(5, new TreeNode(3), new TreeNode(12));
    runTest(root9, root10, {3, 5, 7, 8, 10, 12, 15});

    TreeNode* root11 = new TreeNode(1, nullptr, new TreeNode(5));
    TreeNode* root12 = new TreeNode(4, new TreeNode(2, new TreeNode(1), nullptr), new TreeNode(6));
    runTest(root11, root12, {1, 1, 2, 4, 5, 6});

    TreeNode* root13 = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    TreeNode* root14 = nullptr;
    runTest(root13, root14, {1, 2, 3});

    TreeNode* root15 = nullptr;
    TreeNode* root16 = nullptr;
    runTest(root15, root16, {});

    return 0;
}
