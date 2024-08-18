#include <iostream>
#include <bitset>

using namespace std;

int findComplement(int num) {
    unsigned mask = 2147483648;

    while(mask / 2 > num) {
        mask >>= 1;
    }

    return num ^ --mask;
}

void printBinary(int num) {
    cout << bitset<32>(num) << endl;
}

int main() {
    int numbers[] = {5, 1, 8, 15, 1023};
    int numExamples = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 0; i < numExamples; ++i) {
        int num = numbers[i];
        int complement = findComplement(num);

        cout << "Number: " << num << "\t(" << bitset<32>(num) << ")" << endl;
        cout << "Complement: " << complement << "\t(" << bitset<32>(complement) << ")" << endl;
        cout << endl;
    }

    return 0;
}
