#include <iostream>
#include <vector>
#include <cstdlib>

using  namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums)
    {
        vector<int> result(nums.size());
        result[0] = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            result[i] = nums[i] + result[i - 1];


        }
          for(int num : result) {
        cout << num << " ";
    }

          return result;

    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    s.runningSum(nums);



    return 0;
}
