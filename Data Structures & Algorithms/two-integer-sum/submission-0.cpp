class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> IndicesThatHaveNumsEqualTarget = {};
        const int TotalNums = nums.size();
        
        for(int i = 0; i < TotalNums; ++i)
        {
            for(int j = i+1; j < TotalNums; ++j)
            {
                if (nums[i] + nums[j] == target)
                {
                    IndicesThatHaveNumsEqualTarget.push_back(i);
                    IndicesThatHaveNumsEqualTarget.push_back(j);
                    return IndicesThatHaveNumsEqualTarget;
                }
            }
        }

         return IndicesThatHaveNumsEqualTarget;
    }
};
