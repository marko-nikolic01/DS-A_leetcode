#include <iostream>
#include <vector>

using namespace std;

class Bank {
    private:
        vector<long long>& balance;

    public:
        Bank(vector<long long>& balance) : balance(balance) {}

        bool transfer(int account1, int account2, long long money) {
            int n = balance.size();
            if(account1 > n || account2 > n || balance[--account1] < money) {
                return false;
            }

            balance[account1] -= money;
            balance[--account2] += money;

            return true;
        }

        bool deposit(int account, long long money) {
            if(account > balance.size()) {
                return false;
            }

            balance[--account] += money;

            return true;
        }

        bool withdraw(int account, long long money) {
            if(account > balance.size() || balance[--account] < money) {
                return false;
            }

            balance[account] -= money;

            return true;
        }
};

void printArray(vector<string> array) {
    for(string a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<string> commands, vector<vector<long long>> inputs, vector<string> expected) {
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

    Bank* bank;

    vector<string> results;
    for(int i = 0; i < commands.size(); i++) {
        if(commands[i] == "Bank") {
            bank = new Bank(inputs[i]);
            results.push_back("null");
        } else if(commands[i] == "transfer") {
            results.push_back(bank->transfer(inputs[i][0], inputs[i][1], inputs[i][2]) ? "true" : "false");
        } else if(commands[i] == "deposit") {
            results.push_back(bank->deposit(inputs[i][0], inputs[i][1]) ? "true" : "false");
        } else if(commands[i] == "withdraw") {
            results.push_back(bank->withdraw(inputs[i][0], inputs[i][1]) ? "true" : "false");
        }
    }

    cout << "Expected: ";
    printArray(expected);

    cout << "Results: ";
    printArray(results);

    cout << endl;
}

int main() {
    test({"Bank", "withdraw", "transfer", "deposit", "transfer", "withdraw"}, {{{10, 100, 20, 50, 30}}, {3, 10}, {5, 1, 20}, {5, 20}, {3, 4, 15}, {10, 50}}, {"null", "true", "true", "true", "false", "false"});
    test({"Bank", "deposit", "deposit", "deposit"}, {{{5, 5, 5}}, {1, 10}, {2, 20}, {3, 30}}, {"null", "true", "true", "true"});
    test({"Bank", "withdraw", "withdraw", "withdraw"}, {{{50, 100, 30}}, {1, 10}, {2, 100}, {3, 40}}, {"null", "true", "true", "false"});
    test({"Bank", "transfer", "transfer", "transfer"}, {{{10, 20, 30, 40}}, {1, 2, 5}, {3, 4, 10}, {4, 1, 50}}, {"null", "true", "true", "true"});
    test({"Bank", "deposit", "withdraw", "transfer"}, {{{100, 50, 25}}, {2, 50}, {3, 20}, {1, 3, 70}}, {"null", "true", "true", "true"});

    return 0;
}
