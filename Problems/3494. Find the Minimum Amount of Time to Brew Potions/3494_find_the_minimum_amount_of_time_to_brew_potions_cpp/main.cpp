#include <iostream>
#include <vector>

using namespace std;

long long minTime(vector<int>& skill, vector<int>& mana) {
    short nWizards = skill.size();
    vector<long> wizards(nWizards, 0);
    long time;

    short iWizards;
    short nPotions = mana.size();
    for(short iPotions = 0; iPotions < nPotions; ++iPotions) {
        time = 0;

        for(iWizards = 0; iWizards < nWizards; ++iWizards) {
            time = max(time, wizards[iWizards]) + skill[iWizards] * mana[iPotions];
        }

        wizards[nWizards - 1] = time;

        for(iWizards = nWizards - 2; iWizards > -1; --iWizards) {
            wizards[iWizards] = wizards[iWizards + 1] - skill[iWizards + 1] * mana[iPotions];
        }
    }

    return wizards[--nWizards];
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> skill, vector<int> mana, long long expected) {
    cout << "Skill: ";
    printArray(skill);

    cout << "Mana: ";
    printArray(mana);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minTime(skill, mana) << endl;

    cout << endl;
}

int main() {
    test({1, 5, 2, 4}, {5, 1, 4, 2}, 110);
    test({1, 1, 1}, {1, 1, 1}, 5);
    test({3}, {7}, 21);
    test({2, 3}, {4}, 20);
    test({2}, {1, 2, 3}, 12);

    return 0;
}
