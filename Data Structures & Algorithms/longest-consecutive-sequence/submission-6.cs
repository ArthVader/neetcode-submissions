public class Solution {
    public int LongestConsecutive(int[] nums) {
        
        if(nums.Length == 0)
        {
            return 0;
        }

        SortedSet<int> sortedSet = new SortedSet<int>(nums);

        int currentLongestConsecutive = 1;
        int maxLongestConsecutive = 1;
        int prevNum = -1;
        bool isFirstIteration = true;

        foreach(int num in sortedSet)
        {
            if(isFirstIteration)
            {
                isFirstIteration = false;
                prevNum = num;
                continue;
            }

            if(prevNum+1 == num)
            {
                ++currentLongestConsecutive;
            }
            else
            {
                if(currentLongestConsecutive > maxLongestConsecutive)
                {
                    maxLongestConsecutive = currentLongestConsecutive;
                }

                currentLongestConsecutive = 1;
            }

            prevNum = num;
        }

        if(currentLongestConsecutive > maxLongestConsecutive)
        {
            maxLongestConsecutive = currentLongestConsecutive;
        }

        return maxLongestConsecutive;
    }
}
