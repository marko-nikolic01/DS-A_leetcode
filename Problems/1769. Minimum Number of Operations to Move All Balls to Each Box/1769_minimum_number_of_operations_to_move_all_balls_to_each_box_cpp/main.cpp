#include <iostream>
#include <vector>

using namespace std;

vector<int> minOperations(string boxes) {
    int left = 0;
    int right = 0;

    int n = boxes.length();
    vector<int> result(n);

    for(int i = 1; i < n; ++i) {
        if(boxes[i] == '1') {
            ++right;
            result[0] += i;
        }
    }

    for(int i = 1; i < n; ++i) {
        if(boxes[i - 1] == '1') {
            ++left;
        }

        result[i] = result[i - 1] + left - right;

        if(boxes[i] == '1') {
            --right;
        }
    }


    return result;
}

void test(string boxes, vector<int> expected) {
    cout << "Boxes: " << boxes << endl;

    cout << "Expected: ";
    for (int i : expected) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Result:   ";
    for (int result : minOperations(boxes)) {
        cout << result << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    test("000", {0, 0, 0});
    test("001", {2, 1, 0});
    test("100", {0, 1, 2});
    test("101", {2, 2, 2});
    test("00100", {2, 1, 0, 1, 2});
    test("110", {1, 1, 3});
    test("001011", {11, 8, 5, 4, 3, 4});
    test("111", {3, 2, 3});

    return 0;
}
