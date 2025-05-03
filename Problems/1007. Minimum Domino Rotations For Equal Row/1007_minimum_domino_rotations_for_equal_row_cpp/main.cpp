#include <iostream>
#include <vector>

using namespace std;

int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
    int rotationsTop = 0;
    int rotationsBottom = 0;
    int noRotationsTop = 0;
    int noRotationsBottom = 0;

    int i;
    int n = tops.size();
    for(i = 0; i < n; ++i) {
        if(tops[i] == bottoms[i]) {
            if(rotationsTop > -1) {
                if(tops[0] == tops[i]) {
                    ++noRotationsTop;
                } else {
                    if(rotationsBottom < 0) {
                        return -1;
                    }
                    rotationsTop = -1;
                }
            }

            if(rotationsBottom > -1) {
                if(bottoms[0] == bottoms[i]) {
                    ++noRotationsBottom;
                } else {
                    if(rotationsTop < 0) {
                        return -1;
                    }
                    rotationsBottom = -1;
                }
            }
        } else {
            if(rotationsTop > -1) {
                if(tops[0] == bottoms[i]) {
                    ++rotationsTop;
                } else if(tops[0] != tops[i]) {
                    if(rotationsBottom < 0) {
                        return -1;
                    }
                    rotationsTop = -1;
                }
            }

            if(rotationsBottom > -1) {
                if(bottoms[0] == tops[i]) {
                    ++rotationsBottom;
                } else if(bottoms[0] != bottoms[i]) {
                    if(rotationsTop < 0) {
                        return -1;
                    }
                    rotationsBottom = -1;
                }
            }
        }
    }

    i = n;

    if(rotationsTop > -1) {
        i = rotationsTop;

        rotationsTop = n - rotationsTop - noRotationsTop;
        if(rotationsTop < i) {
            i = rotationsTop;
        }
    }

    if(rotationsBottom > -1) {
        if(rotationsBottom < i) {
            i = rotationsBottom;
        }

        rotationsBottom = n - rotationsBottom - noRotationsBottom;
        if(rotationsBottom < i) {
            i = rotationsBottom;
        }
    }

    return i;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> tops, vector<int> bottoms, int expected) {
    cout << "Tops: ";
    printArray(tops);

    cout << "Bottoms: ";
    printArray(bottoms);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minDominoRotations(tops, bottoms) << endl;

    cout << endl;
}

int main() {
    test({2,1,2,4,2,2}, {5,2,6,2,3,2}, 2);
    test({3,5,1,2,3}, {3,6,3,3,4}, -1);
    test({4,4,4,4}, {2,2,2,2}, 0);
    test({1,2,1,1}, {2,1,2,2}, 1);
    test({1,2,3,4,6}, {6,6,6,6,5}, 1);
    test({1,2,3,4,5}, {6,6,6,6,5}, -1);
}
