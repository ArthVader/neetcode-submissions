public class Solution {
    public bool hasDuplicate(int[] nums) {
        
        Dictionary<int, int> DuplicateLookup = new Dictionary<int, int>();

        foreach (int num in nums)
        {
            if(DuplicateLookup.ContainsKey(num))
            {
                return true;
            }
            else
            {
                DuplicateLookup[num] = 1; //or use DuplicateLookup.Add(num, 1)
            }
        }

        return false;
    }
}