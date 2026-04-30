public class Solution {
    public int[] TwoSum(int[] nums, int target) {

        int[] IndicesThatHaveNumsEqualTarget = new int[2];
        int TotalNums = nums.Length;
        
        for(int i = 0; i < TotalNums; ++i)
        {
            for(int j = i+1; j < TotalNums; ++j)
            {
                if (nums[i] + nums[j] == target)
                {
                    IndicesThatHaveNumsEqualTarget[0] = i;
                    IndicesThatHaveNumsEqualTarget[1] = j;
                    return IndicesThatHaveNumsEqualTarget;
                }
            }
        }

         return IndicesThatHaveNumsEqualTarget;
    }
}
