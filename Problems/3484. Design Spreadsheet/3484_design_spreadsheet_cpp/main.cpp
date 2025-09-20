#include <iostream>
#include <vector>

using namespace std;

class Spreadsheet {
    private:
        vector<vector<int>> spreadsheet;

    public:
        Spreadsheet(int rows) : spreadsheet(rows, vector<int>(26, 0)) {}

        void setCell(string cell, int value) {
            short column = cell[0] - 'A';
            short row = 0;

            short n = cell.size();
            for(short i = 1; i < n; ++i) {
                row = (10 * row) + cell[i] - '0';
            }

            spreadsheet[--row][column] = value;
        }

        void resetCell(string cell) {
            setCell(cell, 0);
        }

        int getValue(string formula) {
            int sum = 0;
            short column;
            int row;

            short n = formula.size();
            for(short i = 1; i < n; ++i) {
                if(formula[i] > '@') {
                    column = formula[i] - 'A';
                    row = 0;
                } else {
                    column = -1;
                    row = formula[i] - '0';
                }

                while(++i < n && formula[i] > '+') {
                    row = (row * 10) + formula[i] - '0';
                }

                sum += column > -1 ? spreadsheet[--row][column] : row;
            }

            return sum;
        }
};

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void printArray(vector<string> array) {
    for(string a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<string> commands, vector<vector<string>> inputs, vector<string> expected) {
    cout << "Commands: ";
    printArray(commands);

    cout << "Inputs: ";
    for(int i = 0; i < inputs.size(); i++) {
        cout << "[";
        for(int j = 0; j < inputs[i].size(); j++) {
            cout << inputs[i][j];
            if(j != inputs[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "] ";
    }
    cout << endl;

    Spreadsheet* spreadsheet;

    vector<string> results;
    for(int i = 0; i < commands.size(); i++) {
        if(commands[i] == "Spreadsheet") {
            spreadsheet = new Spreadsheet(stoi(inputs[i][0]));
            results.push_back("null");
        } else if(commands[i] == "setCell") {
            spreadsheet->setCell(inputs[i][0], stoi(inputs[i][1]));
            results.push_back("null");
        } else if(commands[i] == "resetCell") {
            spreadsheet->resetCell(inputs[i][0]);
            results.push_back("null");
        } else if(commands[i] == "getValue") {
            results.push_back(to_string(spreadsheet->getValue(inputs[i][0])));
        }
    }

    cout << "Expected: ";
    printArray(expected);

    cout << "Results: ";
    printArray(results);

    cout << endl;
}

int main() {
    test({"Spreadsheet", "getValue", "setCell", "getValue", "setCell", "getValue", "resetCell", "getValue"}, {{"3"}, {"=5+7"}, {"A1", "10"}, {"=A1+6"}, {"B2", "15"}, {"=A1+B2"}, {"A1"}, {"=A1+B2"}}, {"null", "12", "null", "16", "null", "25", "null", "15"});
    test({"Spreadsheet", "getValue"}, {{"941"}, {"=J454+34128"}}, {"null", "34128"});
    test({"Spreadsheet", "setCell", "resetCell"}, {{"24"}, {"B24", "66688"}, {"O15"}}, {"null", "null", "null"});
    test({"Spreadsheet", "setCell", "setCell", "getValue", "resetCell", "getValue"}, {{"5"}, {"C3", "50"}, {"D4", "70"}, {"=C3+D4"}, {"C3"}, {"=C3+D4"}}, {"null", "null", "null", "120", "null", "70"});
    test({"Spreadsheet", "getValue", "getValue", "getValue"}, {{"2"}, {"=100+200"}, {"=99999+1"}, {"=0+0"}}, {"null", "300", "100000", "0"});

    return 0;
}
