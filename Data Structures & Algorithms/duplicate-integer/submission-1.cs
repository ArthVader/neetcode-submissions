public class Solution {
    public bool hasDuplicate(int[] nums) {
        
        HashSet<int> DuplicateLookup = new HashSet<int>();

        foreach (int num in nums)
        {
            if(DuplicateLookup.Contains(num))
            {
                return true;
            }
            else
            {
                DuplicateLookup.Add(num);
            }
        }

        return false;
    }
}