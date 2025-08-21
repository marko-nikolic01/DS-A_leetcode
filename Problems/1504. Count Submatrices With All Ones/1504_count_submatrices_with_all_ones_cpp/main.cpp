#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int numSubmat(vector<vector<int>>& mat) {
    short n = mat[0].size();
    vector<int> heights(n, 0);
    int result = 0;
    int prev;
    int cur;
    int h;

    int j;
    int k;
    int m = mat.size();
    for(int i = 0; i < m; ++i) {
        for(j = 0; j < n; ++j) {
            heights[j] = (mat[i][j] == 0) ? 0 : heights[j] + 1;
        }

        vector<vector<int>> st;
        st.push_back({-1, 0, -1});

        for(j = 0; j < n; ++j) {
            h = heights[j];

            while(st.back()[2] >= h) {
                st.pop_back();
            }

            auto& top = st.back();
            k = top[0];
            prev = top[1];
            cur = prev + (j - k) * h;
            st.push_back({j, cur, h});
            result += cur;
        }
    }

    return result;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> mat, int expected) {
    cout << "Matrix:" << endl;
    printMatrix(mat);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numSubmat(mat) << endl;

    cout << endl;
}

int main()
{
    test({{1, 0, 1}, {1, 1, 0}, {1, 1, 0}}, 13);
    test({{0, 1, 1, 0}, {0, 1, 1, 1}, {1, 1, 1, 0}}, 24);
    test({{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}, 36);
    test({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, 0);
    test({{1, 0, 1, 1}, {1, 1, 1, 1}, {0, 1, 1, 0}, {1, 1, 0, 0}}, 30);

    return 0;
}
