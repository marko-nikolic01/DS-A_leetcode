#include <iostream>
#include <unordered_map>

using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> digits = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int result = 0;

    int n = s.length();
    for(int i = n - 1; i >= 0; --i) {
        if (i != n - 1 && digits[s[i]] < digits[s[i + 1]]){
            result -= digits[s[i]];
        } else {
            result += digits[s[i]];
        }
    }

    return result;
}

int main()
{
    string s = "IV";

    int result = romanToInt(s);

    cout << "Roman number " << s << " is equal to " << result << "." << endl;
    return 0;
}
