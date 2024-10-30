#include <iostream>

using namespace std;

string interpret(string command) {
    string interpretation = "";

    int n = command.length();
    for(int i = 0; i < n; ++i) {
        if(command[i] =='G') {
            interpretation.push_back('G');
        } else if(command[++i] == ')') {
            interpretation.push_back('o');
        }else {
            interpretation.push_back('a');
            interpretation.push_back('l');
            i += 2;
        }
    }

    return interpretation;
}

void test(string command, string expected) {
    cout << "Command: " << command << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << interpret(command) << endl;

    cout << endl;
}

int main() {
    test("G()(al)", "Goal");
    test("G()()()()(al)", "Gooooal");
    test("(al)G(al)()()G", "alGalooG");
    test("G(al)()", "Galo");
    test("G", "G");
    test("()", "o");
    test("(al)", "al");

    return 0;
}
