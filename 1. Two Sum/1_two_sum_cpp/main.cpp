#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int> result;

    unordered_map<int, int> complements;

    for(vector<int>::iterator i = nums.begin(); i != nums.end(); i++) {
        int complement = target - *i;

        if(complements.find(complement) != complements.end()) {
            result.push_back(complements[complement]);
            result.push_back(distance(nums.begin(), i));
            break;
        }

        complements[*i] = distance(nums.begin(), i);
    }

    return result;
}

int main()
{
    vector<int> nums = {2,7,11,15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    if (result.size() == 2) {
        cout << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No two sum solution found" << endl;
    }
    return 0;
}
