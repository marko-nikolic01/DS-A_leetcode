#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
    sort(players.begin(), players.end());
    sort(trainers.begin(), trainers.end());

    int iPlayers = 0;
    int iTrainers = 0;
    int nPlayers = players.size();
    int nTrainers = trainers.size();
    while(iPlayers < nPlayers && iTrainers < nTrainers) {
        while(iTrainers < nTrainers && players[iPlayers] > trainers[iTrainers]) {
            ++iTrainers;
        }

        if(iTrainers < nTrainers) {
            ++iPlayers;
            ++iTrainers;
        }
    }

    return iPlayers;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> players, vector<int> trainers, int expected) {
    cout << "Players: ";
    printArray(players);

    cout << "Trainers: ";
    printArray(trainers);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << matchPlayersAndTrainers(players, trainers) << endl;

    cout << endl;
}

int main() {
    test({4, 7, 9}, {8, 2, 5, 8}, 2);
    test({1, 1, 1}, {10}, 1);
    test({10, 15, 20}, {5, 6, 7}, 0);
    test({3, 5, 7}, {3, 5, 7}, 3);
    test({2, 4}, {1, 2, 3, 4, 5}, 2);

    return 0;
}
