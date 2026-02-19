#include <iostream>
#include <vector>

using namespace std;

class ParkingSystem {
    private:
        vector<short> parkingSpaces;

    public:
        ParkingSystem(int big, int medium, int small) : parkingSpaces({(short)big, (short)medium, (short)small}) {}

        bool addCar(int carType) {
            return --parkingSpaces[--carType] > -1;
        }
};

void printArray(vector<string> array) {
    for(string a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<string> commands, vector<vector<int>> inputs, vector<string> expected) {
    cout << "Commands: ";
    printArray(commands);

    cout << "Inputs: ";
    for(int i = 0; i < inputs.size(); ++i) {
        cout << "[";
        for(int j = 0; j < inputs[i].size(); ++j) {
            cout << inputs[i][j];
            if(j != inputs[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "] ";
    }
    cout << endl;

    ParkingSystem* parkingSystem;

    vector<string> results;
    for(int i = 0; i < commands.size(); i++) {
        if(commands[i] == "ParkingSystem") {
            parkingSystem = new ParkingSystem(inputs[i][0], inputs[i][1], inputs[i][2]);
            results.push_back("null");
        } else if(commands[i] == "addCar") {
            results.push_back((parkingSystem->addCar(inputs[i][0]) ? "true" : "false"));
        }
    }

    cout << "Expected: ";
    printArray(expected);

    cout << "Results:  ";
    printArray(results);

    cout << endl;
}

int main() {
    test({"ParkingSystem", "addCar", "addCar", "addCar", "addCar"}, {{1, 1, 0}, {1}, {2}, {3}, {1}}, {"null", "true", "true", "false", "false"});
    test({"ParkingSystem", "addCar", "addCar"}, {{1, 0, 0}, {1}, {1}}, {"null", "true", "false"});
    test({"ParkingSystem", "addCar", "addCar", "addCar"}, {{0, 0, 0}, {1}, {2}, {3}}, {"null", "false", "false", "false"});
    test({"ParkingSystem", "addCar", "addCar", "addCar"}, {{1, 1, 1}, {1}, {2}, {3}}, {"null", "true", "true", "true"});
    test({"ParkingSystem", "addCar", "addCar", "addCar"}, {{0, 0, 2}, {3}, {3}, {3}}, {"null", "true", "true", "false"});

    return 0;
}
