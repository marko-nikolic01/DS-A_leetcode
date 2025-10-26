#include <iostream>
#include <vector>

using namespace std;

class ATM {
    private:
        vector<int> banknotes;
        vector<short> denominations;

    public:
        ATM() : banknotes(5, 0) {
            denominations = {20, 50, 100, 200, 500};
        }

        void deposit(vector<int> banknotesCount) {
            for(short i = 0; i < 5; ++i) {
                banknotes[i] += banknotesCount[i];
            }
        }

        vector<int> withdraw(int amount) {
            vector<int> withdrawal(5, 0);

            short i;
            for(i = 4; i > -1; --i) {
                if(denominations[i] <= amount) {
                    withdrawal[i] = min(banknotes[i], amount / denominations[i]);
                    amount -= withdrawal[i] * denominations[i];
                }
            }

            if(amount > 0) {
                return {-1};
            }

            for(i = 0; i < 5; ++i) {
                banknotes[i] -= withdrawal[i];
            }

            return withdrawal;
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

    ATM* atm;

    vector<string> results;
    for(int i = 0; i < commands.size(); i++) {
        if(commands[i] == "ATM") {
            atm = new ATM();
            results.push_back("null");
        } else if(commands[i] == "deposit") {
            atm->deposit(inputs[i]) ;
            results.push_back("null");
        } else if(commands[i] == "withdraw") {
            string result = "";
            vector<int> r = atm->withdraw(inputs[i][0]);

            result.push_back('[');
            for(int j = 0; j < r.size(); ++j) {
                result.append(to_string(r[j]));
                if(j != r.size() - 1) {
                    result.push_back(',');
                    result.push_back(' ');
                }
            }
            result.push_back(']');

            results.push_back(result);
        }
    }

    cout << "Expected: ";
    printArray(expected);

    cout << "Results: ";
    printArray(results);

    cout << endl;
}

int main() {
    test({"ATM", "deposit", "withdraw", "deposit", "withdraw", "withdraw"}, {{}, {0, 0, 1, 2, 1}, {600}, {0, 1, 0, 1, 1}, {600}, {550}}, {"null", "null", "[0, 0, 1, 0, 1]", "null", "[-1]", "[0, 1, 0, 0, 1]"});
    test({"ATM", "deposit", "withdraw"}, {{}, {0, 10, 0, 3, 0}, {500}}, {"null", "null", "[0, 2, 0, 2, 0]"});
    test({"ATM", "deposit", "withdraw"}, {{}, {0, 0, 0, 0, 0}, {500}}, {"null", "null", "[-1]"});
    test({"ATM", "deposit", "withdraw"}, {{}, {1, 1, 1, 1, 1}, {370}}, {"null", "null", "[1, 1, 1, 1, 0]"});
    test({"ATM", "deposit", "withdraw"}, {{}, {0, 2, 0, 0, 3}, {1050}}, {"null", "null", "[0, 1, 0, 0, 2]"});

    return 0;
}
