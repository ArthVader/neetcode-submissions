public class Solution {
    private int IsCorrect(int num, int target)
    {
        if(num > target)
        {
            return 1;
        }
        else if(num < target)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }

    public int Search(int[] nums, int target) {
        
        int low = 0;
        int high = nums.Length - 1;
        int midPoint = -1;

        while(low <= high)
        {
            midPoint = (low + high) / 2;

            if(IsCorrect(nums[midPoint], target) > 0)
            {
                high = midPoint - 1;
            }
            else if(IsCorrect(nums[midPoint], target) < 0)
            {
                low = midPoint + 1;
            }
            else
            {
                return midPoint;
            }
        }

        return -1;
    }
}
