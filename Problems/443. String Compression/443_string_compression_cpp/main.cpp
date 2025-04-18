#include <iostream>
#include <vector>

using namespace std;

int compress(vector<char>& chars) {
    short length = 0;
    char current;
    short currentLength;
    short currentIndex = 0;
    short powerOf10;

    short n = chars.size();
    for(short i = 0; i < n; ++i) {
        ++length;
        current = chars[i];
        currentLength = 1;
        chars[currentIndex++] = current;

        while(++i < n && chars[i] == current) {
            ++currentLength;
        }
        --i;

        if(currentLength > 1) {
            powerOf10 = 1;
            while(powerOf10 <= currentLength) {
                powerOf10 *= 10;
            }
            powerOf10 /= 10;

            while(powerOf10 > 0) {
                ++length;
                chars[currentIndex++] = '0' + currentLength / powerOf10;
                currentLength %= powerOf10;
                powerOf10 /= 10;
            }
        }
    }

    chars.resize(currentIndex);

    return length;
}

void printArray(vector<char> array) {
    cout << "\"";
    for(char a : array) {
        cout << a;
    }
    cout << "\"" << endl;
}

void test(vector<char> chars, int expected, vector<char> expectedChars) {
    cout << "String: ";
    printArray(chars);

    cout << "Expected: " << expected << endl;

    cout << "Expected string: ";
    printArray(expectedChars);

    cout << "Result: " << compress(chars) << endl;

    cout << "Result string: ";
    printArray(chars);

    cout << endl;
}

int main() {
    test({'a','a','b','b','c','c','c'}, 6, {'a','2','b','2','c','3'});
    test({'a'}, 1, {'a'});
    test({'a','b','b','b','b','b','b','b','b','b','b','b','b'}, 4, {'a','b','1','2'});
    test({'x','x','x','y','z','z'}, 5, {'x','3','y','z','2'});
    test({'a','a','a','a','a','a','a','a','a','a','a','a','a','a','a'}, 3, {'a','1','5'});

    return 0;
}
