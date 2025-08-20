#include <iostream>
#include <map>

using namespace std;

void countOfAtoms(string& formula, map<string, int>& atoms, int multiplier, short i, short n) {
    if(i >= n) {
        return;
    }

    if(formula[i] == '(') {
        short count = 1;

        short j = i;
        while(count > 0) {
            if(formula[++j] == '(') {
                ++count;
            } else if(formula[j] == ')') {
                --count;
            }
        }
        short k = j;

        count = 0;
        while(++j < n && formula[j] > '/' && formula[j] < ':') {
            count = 10 * count + formula[j] - '0';
        }

        if(count < 1) {
            ++count;
        }

        countOfAtoms(formula, atoms, multiplier * count, i + 1, k);
        countOfAtoms(formula, atoms, multiplier, j, n);
    } else {
        string atom = "";
        atom.push_back(formula[i]);

        while(++i < n && formula[i] > '`') {
            atom.push_back(formula[i]);
        }
        --i;

        short count = 0;
        while(++i < n && formula[i] > '/' && formula[i] < ':') {
            count = 10 * count + formula[i] - '0';
        }

        atoms[atom] += multiplier * (count > 0 ? count : 1);
        countOfAtoms(formula, atoms, multiplier, i, n);
    }
}

string countOfAtoms(string formula) {
    map<string, int> atoms;
    short n = formula.length();

    countOfAtoms(formula, atoms, 1, 0, n);

    string elements = "";
    int count;
    int powerOf10;

    short i;
    for(map<string, int>::iterator it = atoms.begin(); it != atoms.end(); ++it) {
        n = it->first.length();
        for(i = 0; i < n; ++i) {
            elements.push_back(it->first[i]);
        }

        count = it->second;

        if(count > 1) {
            powerOf10 = 1;
            while(powerOf10 <= count) {
                powerOf10 *= 10;
            }
            powerOf10 /= 10;

            while(powerOf10 > 0) {
                elements.push_back('0' + count / powerOf10);
                count %= powerOf10;
                powerOf10 /= 10;
            }
        }
    }

    return elements;
}

void test(string formula, string expected) {
    cout << "Formula: " << formula << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countOfAtoms(formula) << endl;

    cout << endl;
}

int main() {
    test("H2O", "H2O");
    test("Mg(OH)2", "H2MgO2");
    test("K4(ON(SO3)2)2", "K4N2O14S4");
    test("(Co2Cd39)5", "Cd195Co10");
    test("Be32He2Li", "Be32He2Li");

    return 0;
}
