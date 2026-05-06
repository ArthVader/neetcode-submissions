public class Solution {

    List<int> computePrefixProductList(int [] nums)
    {
        List<int> prefixProductList = new List<int>(nums.Length);

        int runningProduct = 1;
        foreach(int num in nums)
        {
            runningProduct *= num;
            prefixProductList.Add(runningProduct);
        }

        return prefixProductList;
    }

    List<int> computePostfixProductList(int [] nums)
    {
        // declare the list this way to fill each slot with 0, otherwise the slots will be reserved but not intitialized and cant be assigned by index yet.
        List<int> postfixProductList = new List<int>(new int[nums.Length]);

        int runningProduct = 1;
        for (int i = postfixProductList.Count-1; i > -1; --i)
        {
            runningProduct *= nums[i];
            postfixProductList[i] = runningProduct;
        }

        return postfixProductList;
    }

    public int[] ProductExceptSelf(int[] nums) {
        
        // Todo, replace all lists with fixed size in arrays
        List<int> prefixProductList = computePrefixProductList(nums);
        List<int> postfixProductList = computePostfixProductList(nums);

        // Store as a List, which is an internally managed array that can grow in size. Arrays in C# are contiguous and cannot be resized.
        List<int> productExceptSelfList = new List<int>();

        for(int i = 0; i < nums.Length; ++i)
        {
            int prefixProduct = i > 0 ? prefixProductList[i-1] : 1;
            int postfixProduct = i < nums.Length-1 ? postfixProductList[i+1] : 1;
            int product = prefixProduct * postfixProduct;

            productExceptSelfList.Add(product);
        }

        // Convert to Array
        return productExceptSelfList.ToArray();
    }
}
