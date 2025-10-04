#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
    unordered_map<int, vector<int>> adjacentElements;

    int i;
    for(i = adjacentPairs.size() - 1; i > -1; --i) {
        adjacentElements[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
        adjacentElements[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
    }

    vector<int> array(adjacentElements.size());
    int next;
    int previous;

    for(unordered_map<int, vector<int>>::iterator it = adjacentElements.begin(); it != adjacentElements.end(); ++it) {
        if(it->second.size() < 2) {
            next = it->first;
            previous = next;

            while(true) {
                array[++i] = next;

                if(adjacentElements[next][0] != previous) {
                    previous = next;
                    next = adjacentElements[next][0];
                } else if(adjacentElements[next].size() > 1) {
                    previous = next;
                    next = adjacentElements[next][1];
                } else {
                    break;
                }
            }

            break;
        }
    }

    return array;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<vector<int>> adjacentPairs, vector<int> expected) {
    cout << "Adjacent pairs: ";
    for(vector<int> adjacentPair : adjacentPairs) {
        cout << "[" << adjacentPair[0] << " " << adjacentPair[1] << "] ";
    }
    cout << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(restoreArray(adjacentPairs));

    cout << endl;
}

int main() {
    test({{2, 1}, {3, 4}, {3, 2}}, {1, 2, 3, 4});
    test({{4, -2}, {1, 4}, {-3, 1}}, {-2, 4, 1, -3});
    test({{100000, -100000}}, {100000, -100000});
    test({{1, 2}, {2, 3}, {3, 4}, {4, 5}}, {1, 2, 3, 4, 5});
    test({{10, 20}, {30, 20}, {40, 30}}, {10, 20, 30, 40});

    return 0;
}
