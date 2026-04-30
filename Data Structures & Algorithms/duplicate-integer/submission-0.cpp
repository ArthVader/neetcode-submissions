class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        
        map<int, int> NumFrequency = {};
        for (const int & num: nums)
        {
            if(NumFrequency[num]++)
            {
                return true;
            }
        }

        return false;
    }
};