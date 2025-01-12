#include <iostream>

using namespace std;

bool canBeValid(string s, string locked) {
    int open = 0;
    int any = 0;
    int closed = 0;

    int n = s.length();
    for(int i = 0; i < n; ++i) {
        if(locked[i] == '0') {
        ++any;
        } else if(s[i] == '(') {
            ++open;
        } else {
            ++closed;
        }
    }

    cout << "CLOSED: " << closed << endl;
    cout << "ANY: " << any << endl;
    cout << "OPEN: " << open << endl;

    any = 0;
    closed = 0;
    int a = 0;

    if(open > 0) {
        for(--n; n > -1; --n) {
            if(locked[n] == '0') {
                ++any;
            } else if(s[n] == ')') {
                if(++closed == open) {
                cout << "BRUHHHHH" << endl;
                cout << open << endl;
                cout << closed << endl;
                    closed = 0;
                    break;
                }
            } else if(closed > 0) {
                --closed;
                --open;
            } else if(any > 0) {
            ++a;
                --any;
                if(--open == 0) {
                cout << "OKKKKKKKKKKKK" << endl;
                    break;
                }
            } else {
                return false;
            }

        }
    }

    cout << "STOPPED AT N: " << n << endl;
    cout << "CLOSED: " << closed << endl;
    cout << "ANY: " << any << endl;
    cout << "AAAAAAAAAA: " << a << endl;

    for(--n; n > -1; --n) {
        if(locked[n] == '0') {
            if(closed > 0) {
                --closed;
            } else {
                ++any;
            }
        } else if(s[n] == ')') {
            ++closed;
        }
        cout << "ITERATION: " << n << "   CLOSED: " << closed << "   ANY: " << any << "   OPEN: " << open << endl << endl;
    }

    cout << "CLOSED: " << closed << endl;
    cout << "ANY: " << any << endl;

    return closed == 0 && any % 2 == 0;
}

string abc(string s, string l) {
    int n = l.length();
    for(int i = 0; i < n; ++i) {
        if(l[i] == '1') {
            s[i] = s[i] == ')' ? '}' : '{';
        }
    }

    return s;
}

int main()
{
    string s = "()()))()())(((()((()((()((()()()))(()()((()((()()(((()())))))()((()(()(())((()()((())))))))(())(())))()()()((()())())(()()))((((((())()())())))))())((((()())(())(())()()()(()(()((()))((((()((()((()())(())((((())(())))(()((((())))((()(((((()()))))((((()))))())()))))())";
    string l = "0111000100000011110100010110101001110111010111110111111011101000100000011101010000110110001100100100100011000001110101101110011000000011111000111111111001011101100000100111010111010000001100011101000110101011001000100100111110110110100101010111111001000010000010010010";


    cout << abc(s, l) << endl;
    cout << "Hello world!" << endl;
    return 0;
}
