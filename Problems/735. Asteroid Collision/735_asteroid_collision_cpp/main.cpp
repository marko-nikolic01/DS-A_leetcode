#include <iostream>
#include <vector>

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> finalState;

    int n = asteroids.size();

    for(int i = 0; i < n; ++i) {
        if(finalState.size() < 1) {
            finalState.push_back(asteroids[i]);
            continue;
        }

        if(finalState.back() > 0) {
            if(asteroids[i] > 0) {
                finalState.push_back(asteroids[i]);
            } else {
                while(finalState.size() > 0 && finalState.back() > 0 && finalState.back() < -asteroids[i]) {
                    finalState.pop_back();
                }
                if(finalState.size() > 0) {
                    if(finalState.back() > 0) {
                        if(finalState.back() == -asteroids[i]) {
                            finalState.pop_back();
                        }
                    } else {
                        finalState.push_back(asteroids[i]);
                    }
                } else {
                    finalState.push_back(asteroids[i]);
                }

            }
        } else {
            finalState.push_back(asteroids[i]);
        }
    }

    return finalState;
}

void test(vector<int> asteroids, vector<int> expected) {
    cout << "Asteroids: ";
    for (int asteroid : asteroids) {
        cout << asteroid << " ";
    }
    cout << endl;

    cout << "Expected: ";
    for (int exp : expected) {
        cout << exp << " ";
    }
    cout << endl;

    cout << "Result:   ";
    for (int res : asteroidCollision(asteroids)) {
        cout << res << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    test({5, 10, -5}, {5, 10});
    test({8, -8}, {});
    test({10, 2, -5}, {10});
    test({-2, -1, 1, 2}, {-2, -1, 1, 2});
    test({10, -10, 5, -5, 2}, {2});
    test({3, 17, 1, 4, 11, 9}, {3, 17, 1, 4, 11, 9});
    test({-3, -17, -1, -4, -11, -9}, {-3, -17, -1, -4, -11, -9});
    test({1, -1}, {});
    test({-1, 1}, {-1, 1});
    test({-1}, {-1});
    test({1}, {1});

    return 0;
}
