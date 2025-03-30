#include <iostream>
#include <vector>

using namespace std;

int trap(vector<int>& height) {
    int water = 0;

    int left = 0;
    int right = height.size();

    int leftHeight = height[0];
    int rightHeight = height[--right];

    while(left < right) {
        if(leftHeight < rightHeight) {
            if(height[++left] > leftHeight) {
                leftHeight = height[left];
            } else {
                water += leftHeight - height[left];
            }
        } else if(height[--right] > rightHeight) {
            rightHeight = height[right];
        } else {
            water += rightHeight - height[right];
        }
    }

    return water;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> height, int expected) {
    cout << "Heights: ";
    printArray(height);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << trap(height) << endl;

    cout << endl;
}

int main() {
    test({0,1,0,2,1,0,1,3,2,1,2,1}, 6);
    test({4,2,0,3,2,5}, 9);
    test({1,0,2,1,0,1,3}, 5);
    test({2,1,0,2}, 3);
    test({3,0,1,0,2}, 5);
    test({0,0,0,0}, 0);
    test({5,4,3,2,1}, 0);

    return 0;
}
