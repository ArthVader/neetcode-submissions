class Solution {
public:

    int isCorrect(const int num, const int target)
    {
        if(num < target)
        {
            return -1;
        }
        else if (num > target)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int search(vector<int>& nums, int target) {
        
        int low = 0;
        int high = nums.size();
        int midPoint = -1;

        while(low <= high)
        {
            midPoint = (low + high)/2;

            if(isCorrect(nums[midPoint], target) < 0)
            {
                low = midPoint + 1;
            }
            else if(isCorrect(nums[midPoint], target) > 0)
            {
                high = midPoint - 1;
            }
            else
            {
                return midPoint;
            }
        }

        return -1;
    }
};
