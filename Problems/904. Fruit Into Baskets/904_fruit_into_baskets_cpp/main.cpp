#include <iostream>
#include <vector>

using namespace std;

int totalFruit(vector<int>& fruits) {
    int fruit = 0;
    int fruit1 = -1;
    int fruit2 = -1;
    int fruit1Count = 0;
    int fruit2Count = 0;

    int right = fruits.size();
    for(int left = --right; left > -1; --left) {
        if(fruit1 > -1 && fruit2 > -1 && fruit1 != fruits[left] && fruit2 != fruits[left]) {
            while(fruit1Count > 0 && fruit2Count > 0) {
                if(fruit1 == fruits[right--]) {
                    --fruit1Count;
                } else {
                    --fruit2Count;
                }
            }

            if(fruit1Count < 1) {
                fruit1 = -1;
            } else {
                fruit2 = -1;
            }
        }

        if(fruits[left] == fruit1) {
            ++fruit1Count;
        } else if(fruits[left] == fruit2) {
            ++fruit2Count;
        } else if(fruit1 < 0) {
            fruit1 = fruits[left];
            ++fruit1Count;
        } else {
            fruit2 = fruits[left];
            ++fruit2Count;
        }

        if(fruit1Count + fruit2Count > fruit) {
            fruit = fruit1Count + fruit2Count;
        }
    }

    return fruit;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> fruits, int expected) {
    cout << "Fruits: ";
    printArray(fruits);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << totalFruit(fruits) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 1}, 3);
    test({0, 1, 2, 2}, 3);
    test({1, 2, 3, 2, 2}, 4);
    test({1, 1, 1, 1, 1}, 5);
    test({1, 2, 1, 3, 4, 3, 5, 1}, 3);

    return 0;
}
