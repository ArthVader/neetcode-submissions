class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        // Handle empty nums
        if(!nums.size())
        {
            return 0;
        }

        // put all numbers into a sorted set.
        set<int> sortedNumberSet = {};
        for (const int num: nums)
        {
            sortedNumberSet.insert(num);
        }

        // Loop over the set of sorted numbers checking if the prevNum is one less than the current num
        int iterationCount = 0;
        int prevNum = 0;
        int maxLengthOfLongestConsecutiveSequence = 1;
        int currentLengthOfLongestConsecutiveSequence = maxLengthOfLongestConsecutiveSequence;
        for (const int num: sortedNumberSet)
        {
            // assign the previous number on the first iteration.
            if(iterationCount == 0)
            {
                prevNum = num;
                ++iterationCount;
                continue;
            }

            // check the previous number against the current number.
            if(prevNum + 1 == num)
            {
                ++currentLengthOfLongestConsecutiveSequence;
            }
            // if the previous number is not smaller by one than the current number, reset the current currentLengthOfLongestConsecutiveSequence
            else
            {
                // keep track of the longest sequence we tracked.
                if(currentLengthOfLongestConsecutiveSequence > maxLengthOfLongestConsecutiveSequence)
                {
                    maxLengthOfLongestConsecutiveSequence = currentLengthOfLongestConsecutiveSequence;
                }

                // reset the currentLengthOfLongestConsecutiveSequence 
                currentLengthOfLongestConsecutiveSequence = 1;
            }

            // update the previous number.
            prevNum = num;
        }

        // check if currentLengthOfLongestConsecutiveSequence is the longest sequence
        if(currentLengthOfLongestConsecutiveSequence > maxLengthOfLongestConsecutiveSequence)
        {
            maxLengthOfLongestConsecutiveSequence = currentLengthOfLongestConsecutiveSequence;
        }

        return maxLengthOfLongestConsecutiveSequence;
    }
};
