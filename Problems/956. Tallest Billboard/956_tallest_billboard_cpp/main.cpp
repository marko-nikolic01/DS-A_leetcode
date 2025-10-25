#include <iostream>
#include <vector>

using namespace std;

int tallestBillboard(vector<int>& rods) {
    vector<pair<short, short>> billboards;
    vector<vector<bool>> states(5001, vector<bool>(5001, false));
    short rod1;
    short rod2;
    short rod;
    short height = 0;

    billboards.push_back({0, 0});
    states[0][0] = true;

    int j;
    for(short i = rods.size() - 1; i > -1; --i) {
        if(rods[i] < 0) {
            continue;
        }

        for(j = billboards.size() - 1; j > -1; --j) {
            rod1 = billboards[j].first;
            rod2 = billboards[j].second + rods[i];

            if(rod1 > rod2) {
                rod = rod1;
                rod1 = rod2;
                rod2 = rod;
            }

            if(!states[rod1][rod2]) {
                if(rod1 == rod2 && rod1 > height) {
                    height = rod1;
                }

                billboards.push_back({rod1, rod2});
                states[rod1][rod2] = true;
            }

            rod1 = billboards[j].first + rods[i];
            rod2 = billboards[j].second;

            if(rod1 > rod2) {
                rod = rod1;
                rod1 = rod2;
                rod2 = rod;
            }

            if(!states[rod1][rod2]) {
                if(rod1 == rod2 && rod1 > height) {
                    height = rod1;
                }

                billboards.push_back({rod1, rod2});
                states[rod1][rod2] = true;
            }
        }
    }

    return height;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> rods, int expected) {
    cout << "Rods: ";
    printArray(rods);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << tallestBillboard(rods) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 3, 6}, 6);
    test({1, 2, 3, 4, 5, 6}, 10);
    test({1, 2}, 0);
    test({96, 112, 101, 100, 104, 93, 106, 99, 114, 81, 94}, 503);
    test({104, 104, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 99, 98}, 904);
    test({192, 199, 171, 205, 181, 196, 181, 209, 175, 195, 175, 177, 205, 164, 173, 202, 500, 500, 500, 500}, 2500);

    return 0;
}
