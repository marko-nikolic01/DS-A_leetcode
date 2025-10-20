#include <iostream>
#include <vector>

using namespace std;

int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    short nLocations = locations.size();
    vector<vector<int>> routes(nLocations--, vector<int>(++fuel, 0));
    int distance;

    ++routes[start][--fuel];

    short i;
    short j;
    for(short iFuel = fuel; iFuel > -1; --iFuel) {
        for(i = nLocations; i > -1; --i) {
            for(j = nLocations; j > -1; --j) {
                distance = abs(locations[i] - locations[j]);

                if(i == j || distance > iFuel) {
                    continue;
                }

                routes[j][iFuel - distance] = (routes[j][iFuel - distance] + routes[i][iFuel]) % 1000000007;
            }
        }
    }

    int route = 0;

    for(fuel; fuel > -1; --fuel) {
        route = (route + routes[finish][fuel]) % 1000000007;
    }

    return route;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> locations, int start, int finish, int fuel, int expected) {
    cout << "Locations: ";
    printArray(locations);

    cout << "Start: " << start << endl;

    cout << "Finish: " << finish << endl;

    cout << "Fuel: " << fuel << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countRoutes(locations, start, finish, fuel) << endl;

    cout << endl;
}

int main() {
    test({2, 3, 6, 8, 4}, 1, 3, 5, 4);
    test({4, 3, 1}, 1, 0, 6, 5);
    test({5, 2, 1}, 0, 2, 3, 0);
    test({1, 2, 3}, 0, 2, 4, 6);
    test({1, 5, 10}, 0, 2, 10, 2);

    return 0;
}
