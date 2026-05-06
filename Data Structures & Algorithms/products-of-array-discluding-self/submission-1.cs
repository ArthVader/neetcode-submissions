public class Solution {
    public int[] ProductExceptSelf(int[] nums) {
        
        // Store as a List, which is an internally managed array that can grow in size. Arrays in C# are contiguous and cannot be resized.
        List<int> productExceptSelfList = new List<int>();

        for(int i = 0; i < nums.Length; ++i)
        {
            int product = 1;

            for(int j = 0; j < nums.Length; ++j)
            {
                if(i==j)
                {
                    continue;
                }

                product *= nums[j];
            }

            productExceptSelfList.Add(product);
        }

        // Convert to Array
        return productExceptSelfList.ToArray();
    }
}
