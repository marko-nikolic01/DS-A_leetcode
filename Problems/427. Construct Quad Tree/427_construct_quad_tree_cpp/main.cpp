#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
    public:
        bool val;
        bool isLeaf;
        Node* topLeft;
        Node* topRight;
        Node* bottomLeft;
        Node* bottomRight;

        Node() {
            val = false;
            isLeaf = false;
            topLeft = NULL;
            topRight = NULL;
            bottomLeft = NULL;
            bottomRight = NULL;
        }

        Node(bool _val, bool _isLeaf) {
            val = _val;
            isLeaf = _isLeaf;
            topLeft = NULL;
            topRight = NULL;
            bottomLeft = NULL;
            bottomRight = NULL;
        }

        Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
            val = _val;
            isLeaf = _isLeaf;
            topLeft = _topLeft;
            topRight = _topRight;
            bottomLeft = _bottomLeft;
            bottomRight = _bottomRight;
        }
};

Node* construct(vector<vector<int>>& grid, short x1, short x2, short y1, short y2) {
    if(x1 == --x2) {
        return new Node(grid[x1][y1] == 1, true);
    }

    short half = (++x2 - x1) >> 1;

    Node* topLeft = construct(grid, x1, x1 + half, y1, y1 + half);
    Node* topRight = construct(grid, x1, x1 + half, y1 + half, y2);
    Node* bottomLeft = construct(grid, x1 + half, x2, y1, y1 + half);
    Node* bottomRight = construct(grid, x1 + half, x2, y1 + half, y2);

    if(topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf && topLeft->val == topRight->val && topLeft->val == bottomLeft->val && topLeft->val == bottomRight->val) {
        return new Node(topLeft->val, true);
    }

    return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
}

Node* construct(vector<vector<int>>& grid) {
    short n = grid.size();

    return construct(grid, 0, n, 0, n);
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void printTree(Node* root) {
    if(!root) {
        cout << endl;
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        cout << endl;
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();
            if (node) {
                cout << "[" << (node->val ? "true" : "false") << ", " << (node->isLeaf ? "true" : "false") << "] ";
                q.push(node->topLeft);
                q.push(node->topRight);
                q.push(node->bottomLeft);
                q.push(node->bottomRight);
            }
        }
    }
}

void test(vector<vector<int>>& grid, Node* expected) {
    cout << "Matrix:" << endl;
    printMatrix(grid);

    cout << "Expected:";
    printTree(expected);


    cout << "Result:";
    printTree(construct(grid));

    cout << endl;
}

int main() {
    vector<vector<int>> grid1 = {{0}};
    Node* expected1 = new Node(false, true);
    test(grid1, expected1);

    vector<vector<int>> grid2 = {{1}};
    Node* expected2 = new Node(true, true);
    test(grid2, expected2);

    vector<vector<int>> grid3 = {
        {0, 1},
        {1, 0}
    };
    Node* expected3 = new Node(true, false);
    expected3->topLeft = new Node(false, true);
    expected3->topRight = new Node(true, true);
    expected3->bottomLeft = new Node(true, true);
    expected3->bottomRight = new Node(false, true);
    test(grid3, expected3);

    vector<vector<int>> grid4 = {
        {1, 1, 0, 0},
        {0, 0, 1, 1},
        {1, 1, 0, 0},
        {0, 0, 1, 1}
    };
    Node* expected4 = new Node(true, false);
    expected4->topLeft = new Node(true, false);
    expected4->topLeft->topLeft = new Node(true, true);
    expected4->topLeft->topRight = new Node(true, true);
    expected4->topLeft->bottomLeft = new Node(false, true);
    expected4->topLeft->bottomRight = new Node(false, true);
    expected4->topRight = new Node(true, false);
    expected4->topRight->topLeft = new Node(false, true);
    expected4->topRight->topRight = new Node(false, true);
    expected4->topRight->bottomLeft = new Node(true, true);
    expected4->topRight->bottomRight = new Node(true, true);
    expected4->bottomLeft = new Node(true, false);
    expected4->bottomLeft->topLeft = new Node(true, true);
    expected4->bottomLeft->topRight = new Node(true, true);
    expected4->bottomLeft->bottomLeft = new Node(false, true);
    expected4->bottomLeft->bottomRight = new Node(false, true);
    expected4->bottomRight = new Node(true, false);
    expected4->bottomRight->topLeft = new Node(false, true);
    expected4->bottomRight->topRight = new Node(false, true);
    expected4->bottomRight->bottomLeft = new Node(true, true);
    expected4->bottomRight->bottomRight = new Node(true, true);
    test(grid4, expected4);

    vector<vector<int>> grid5 = {
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 0}
    };
    Node* expected5 = new Node(true, false);
    expected5->topLeft = new Node(true, true);
    expected5->topRight = new Node(true, false);
    expected5->topRight->topLeft = new Node(false, true);
    expected5->topRight->topRight = new Node(false, true);
    expected5->topRight->bottomLeft = new Node(true, true);
    expected5->topRight->bottomRight = new Node(true, true);
    expected5->bottomLeft = new Node(true, true);
    expected5->bottomRight = new Node(false, true);
    test(grid5, expected5);

    return 0;
}
