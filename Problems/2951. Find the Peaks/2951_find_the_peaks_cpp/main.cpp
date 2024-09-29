#include <iostream>
#include <vector>

using namespace std;

vector<int> findPeaks(vector<int>& mountain) {
    vector<int> peaks;

    for(int i = mountain.size() - 2; i > 0; --i) {
        if(mountain[i - 1] < mountain[i] && mountain[i] > mountain[i + 1]) {
            peaks.push_back(i--);
        }
    }

    return peaks;
}

void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i != vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}

void testFindPeaks(vector<int> mountain, vector<int> expected) {
    cout << "Mountain: ";
    printVector(mountain);
    cout << endl;

    cout << "Expected: ";
    printVector(expected);
    cout << endl;

    cout << "Result: ";
    printVector(findPeaks(mountain));
    cout << endl;

    cout << endl;
}

int main() {
    vector<int> mountain1 = {1, 3, 5, 4, 3, 2, 1};
    vector<int> expected1 = {2};
    testFindPeaks(mountain1, expected1);

    vector<int> mountain2 = {1, 2, 1, 3, 5, 6, 4, 3, 2};
    vector<int> expected2 = {5, 1};
    testFindPeaks(mountain2, expected2);

    vector<int> mountain3 = {10, 20, 15, 2, 23, 90, 67};
    vector<int> expected3 = {5, 1};
    testFindPeaks(mountain3, expected3);

    vector<int> mountain4 = {1, 2, 3, 4, 5};
    vector<int> expected4 = {};
    testFindPeaks(mountain4, expected4);

    vector<int> mountain5 = {5, 4, 3, 2, 1};
    vector<int> expected5 = {};
    testFindPeaks(mountain5, expected5);

    return 0;
}
