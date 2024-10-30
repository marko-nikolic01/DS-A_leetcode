#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

long long minimumFuelCost(unordered_map<int, unordered_set<int>>& roads, int seats, int& cars, int& availableSeats, int city) {
    long long liters = 0;

    for (unordered_set<int>::iterator it = roads[city].begin(); it != roads[city].end(); ++it) {
        roads[*it].erase(city);

        int incommingCars = 0;
        int incommingSeats = 0;

        liters += minimumFuelCost(roads, seats, incommingCars, incommingSeats, *it) + incommingCars;
        cars += incommingCars;
        availableSeats += incommingSeats;
    }

    int passengers = cars * seats - availableSeats + 1;
    cars = passengers / seats + (passengers % seats > 0 ? 1 : 0);
    availableSeats = cars * seats - passengers;

    return liters;
}

long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
    unordered_map<int, unordered_set<int>> roadMap;
    for(int i = roads.size() - 1; i > -1; --i) {
        roadMap[roads[i][0]].insert(roads[i][1]);
        roadMap[roads[i][1]].insert(roads[i][0]);
    }

    int cars = 0;
    int availableSeats = 0;
    return minimumFuelCost(roadMap, seats, cars, availableSeats, 0);
}

void test(vector<vector<int>>& roads, int seats, long long expected) {
    cout << "Roads:";
    for (const auto& road : roads) {
        cout << " [" << road[0] << ", " << road[1] << "]";
    }
    cout << endl;
    cout << "Seats: " << seats << endl;
    cout << "Expected: " << expected << endl;
    cout << "Result: " << minimumFuelCost(roads, seats) << endl;
    cout << endl;
}

int main() {
    vector<vector<int>> roads1 = {{0, 1}, {1, 2}};
    int seats1 = 2;
    long long expected1 = 2;
    test(roads1, seats1, expected1);

    vector<vector<int>> roads2 = {{0, 1}, {1, 2}, {1, 3}};
    int seats2 = 2;
    long long expected2 = 4;
    test(roads2, seats2, expected2);

    vector<vector<int>> roads3 = {{0, 1}, {1, 2}, {2, 3}, {2, 4}};
    int seats3 = 3;
    long long expected3 = 5;
    test(roads3, seats3, expected3);

    vector<vector<int>> roads4 = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
    int seats4 = 1;
    long long expected4 = 10;
    test(roads4, seats4, expected4);

    vector<vector<int>> roads5 = {{0, 1}, {1, 2}, {1, 3}, {3, 4}};
    int seats5 = 2;
    long long expected5 = 5;
    test(roads5, seats5, expected5);

    return 0;
}
