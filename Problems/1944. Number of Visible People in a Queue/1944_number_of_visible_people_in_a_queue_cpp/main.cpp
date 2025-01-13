#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> canSeePersonsCount(vector<int>& heights) {
    int n = heights.size();
    vector<int> visibility(n, 0);

    stack<int> people;
    people.push(0);

    for(int i = 1; i < n; ++i) {
        while(!people.empty()) {
            ++visibility[people.top()];
            if(heights[i] >= heights[people.top()]) {
                people.pop();
            } else {
                break;
            }
        }

        people.push(i);
    }

    return visibility;
}

void test(vector<int> heights, vector<int> expected) {
    cout << "Heights: ";
    for(int height : heights) {
        cout << height << " ";
    }
    cout << endl;

    cout << "Expected: ";
    for(int e : expected) {
        cout << e << " ";
    }
    cout << endl;

    cout << "Result: ";
    for(int result : canSeePersonsCount(heights)) {
        cout << result << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    test({10, 6, 8, 5, 11, 9}, {3, 1, 2, 1, 1, 0});
    test({5, 1, 2, 3, 10}, {4, 1, 1, 1, 0});
    test({1, 3, 2, 4}, {1, 2, 1, 0});
    test({4, 3, 2, 1}, {1, 1, 1, 0});
    test({1, 2, 3, 4}, {1, 1, 1, 0});
    test({10, 10, 10, 10}, {1,1, 1, 0});

    return 0;
}
