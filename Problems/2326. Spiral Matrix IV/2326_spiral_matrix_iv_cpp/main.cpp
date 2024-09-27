#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    vector<vector<int>> matrix(m, vector<int> (n, -1));

    int x = 0;
    int y = -1;

    int xDirection = 0;
    int yDirection = 1;

    int xMax = m - 1;
    int yMax = n - 1;

    int xMin = 0;
    int yMin = -1;

    while(head) {
        x += xDirection;
        y += yDirection;

        matrix[x][y] = head->val;
        head = head->next;

        if(x == xMin) {
            if(y == yMin) {
                xDirection = 0;
                yDirection = 1;
                xMax--;
            } else if(y == yMax) {
                xDirection = 1;
                yDirection = 0;
                yMin++;
            }
        } else if(x == xMax) {
            if(y == yMin) {
                xDirection = -1;
                yDirection = 0;
                yMax--;
            } else if(y == yMax) {
                xDirection = 0;
                yDirection = -1;
                xMin++;
            }
        }
    }

    return matrix;
}

void test(int m, int n, ListNode* head, const vector<vector<int>>& expected) {
    cout << "m: " << m << endl;

     cout << "n: " << n << endl;

    cout << "Linked: ";
    ListNode* temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    cout << "Expected:" << endl;
    for (const auto& row : expected) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    cout << "Result:" << endl;
    for (const auto& row : spiralMatrix(m, n, head)) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    cout << endl;
}

int main() {
    int m1 = 3, n1 = 3;
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    head1->next->next->next->next->next = new ListNode(6);
    head1->next->next->next->next->next->next = new ListNode(7);
    head1->next->next->next->next->next->next->next = new ListNode(8);
    head1->next->next->next->next->next->next->next->next = new ListNode(9);
    vector<vector<int>> expected1 = {
        {1, 2, 3},
        {8, 9, 4},
        {7, 6, 5}
    };
    test(m1, n1, head1, expected1);

    int m2 = 4, n2 = 3;
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);
    head2->next->next->next->next->next = new ListNode(6);
    head2->next->next->next->next->next->next = new ListNode(7);
    head2->next->next->next->next->next->next->next = new ListNode(8);
    head2->next->next->next->next->next->next->next->next = new ListNode(9);
    head2->next->next->next->next->next->next->next->next->next = new ListNode(10);
    head2->next->next->next->next->next->next->next->next->next->next = new ListNode(11);
    head2->next->next->next->next->next->next->next->next->next->next->next = new ListNode(12);
    vector<vector<int>> expected2 = {
        {1, 2, 3},
        {10, 11, 4},
        {9, 12, 5},
        {8, 7, 6}
    };
    test(m2, n2, head2, expected2);

    int m3 = 1, n3 = 1;
    ListNode* head3 = new ListNode(1);
    vector<vector<int>> expected3 = {{1}};
    test(m3, n3, head3, expected3);

    int m4 = 2, n4 = 2;
    ListNode* head4 = new ListNode(1);
    head4->next = new ListNode(2);
    head4->next->next = new ListNode(3);
    head4->next->next->next = new ListNode(4);
    vector<vector<int>> expected4 = {
        {1, 2},
        {4, 3}
    };
    test(m4, n4, head4, expected4);

    int m5 = 3, n5 = 3;
    ListNode* head5 = new ListNode(1);
    head5->next = new ListNode(2);
    head5->next->next = new ListNode(3);
    head5->next->next->next = new ListNode(4);
    head5->next->next->next->next = new ListNode(5);
    vector<vector<int>> expected5 = {
        {1, 2, 3},
        {-1, -1, 4},
        {-1, -1, 5}
    };
    test(m5, n5, head5, expected5);

    int m6 = 4, n6 = 4;
    ListNode* head6 = new ListNode(1);
    head6->next = new ListNode(2);
    head6->next->next = new ListNode(3);
    head6->next->next->next = new ListNode(4);
    head6->next->next->next->next = new ListNode(5);
    head6->next->next->next->next->next = new ListNode(6);
    head6->next->next->next->next->next->next = new ListNode(7);
    head6->next->next->next->next->next->next->next  = new ListNode(8);
    head6->next->next->next->next->next->next->next ->next  = new ListNode(9);
    vector<vector<int>> expected6 = {
        {1, 2, 3, 4},
        {-1, -1, -1, 5},
        {-1, -1, -1, 6},
        {-1, 9, 8, 7}
    };
    test(m6, n6, head6, expected6);

    return 0;
}
