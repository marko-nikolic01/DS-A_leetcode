#include <iostream>
#include <vector>

using namespace std;

string findDifferentBinaryString(vector<string>& nums) {
    for(short i = nums.size() - 1; i > -1; --i) {
        nums[0][i] = nums[i][i] == '0' ? '1' : '0';
    }

    return nums[0];
}

void test(vector<string> nums, string expected) {
    string result = findDifferentBinaryString(nums);

    cout << "Binary strings: ";
    for (const string& num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << findDifferentBinaryString(nums) << endl;

    cout << endl;
}

int main() {
    test({"01", "10"}, "01");
    test({"00", "01"}, "00");
    test({"111", "011", "001"}, "100");
    test({"000", "001", "010", "011"}, "011");
    test({"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111"}, "0100");

    return 0;
}
