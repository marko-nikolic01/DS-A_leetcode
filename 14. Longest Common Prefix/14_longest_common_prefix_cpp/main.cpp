#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    sort(strs.begin(),strs.end());

    int n = strs.size();
    string str1 = strs[0];
    string str2 = strs[n - 1];

    int count = 0;
    for(int i = 0;i < min(str1.length(),str2.length()); ++i){
        if(str1[i] == str2[i]){
            count++;
        }
        else{
            break;
        }
    }
    return str1.substr(0,count);
}

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};

    string result = longestCommonPrefix(strs);

    cout << "The longest common prefix is: \"" << result << "\"." << endl;
    return 0;
}
