public class Solution {

    int [] computePrefixProductList(int [] nums)
    {
        int[] prefixProductList = new int[nums.Length];

        int runningProduct = 1;
        for (int i = 0; i < nums.Length; ++i)
        {
            runningProduct *= nums[i];
            prefixProductList[i] = runningProduct;
        }

        return prefixProductList;
    }

    int [] computePostfixProductList(int [] nums)
    {
        // declare the list this way to fill each slot with 0, otherwise the slots will be reserved but not intitialized and cant be assigned by index yet.
        int[] postfixProductList = new int[nums.Length];

        int runningProduct = 1;
        for (int i = postfixProductList.Length-1; i > -1; --i)
        {
            runningProduct *= nums[i];
            postfixProductList[i] = runningProduct;
        }

        return postfixProductList;
    }

    public int[] ProductExceptSelf(int[] nums) {
        
        int[] prefixProductList = computePrefixProductList(nums);
        int[] postfixProductList = computePostfixProductList(nums);

        // declare new array the length of the old array.
        int[] productExceptSelfList = new int[nums.Length];

        for(int i = 0; i < nums.Length; ++i)
        {
            int prefixProduct = i > 0 ? prefixProductList[i-1] : 1;
            int postfixProduct = i < nums.Length-1 ? postfixProductList[i+1] : 1;
            productExceptSelfList[i] = prefixProduct * postfixProduct;
        }

        return productExceptSelfList;
    }
}
