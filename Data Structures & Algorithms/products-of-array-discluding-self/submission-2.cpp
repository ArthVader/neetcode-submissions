class Solution {
public:

    vector<int> computePrefixProduct(const vector<int>& nums)
    {
        vector<int> prefixProductList = {};

        int runningProduct = 1;
        for(const int num: nums)
        {
            runningProduct *= num;
            prefixProductList.push_back(runningProduct);
        }

        return prefixProductList;
    }

    vector<int> computePostfixProduct(const vector<int>& nums)
    {
        vector<int> postfixProductList(nums.size());

        int runningProduct = 1;
        for(int i = nums.size() - 1; i > -1; --i)
        {
            runningProduct *= nums[i];
            postfixProductList[i] = runningProduct;
        }

        return postfixProductList;
    }

    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> prefixProductList = computePrefixProduct(nums);
        vector<int> postfixProductList = computePostfixProduct(nums);

        vector<int> productsExceptSelf = {};

        int totalNums = nums.size();
        for(int i = 0; i < totalNums; ++i)
        {
            int prefixProductBeforeI = i > 0 ? prefixProductList[i-1] : 1;
            int postfixProductAfterI = i < totalNums - 1 ? postfixProductList[i+1] : 1; 
            int product = prefixProductBeforeI * postfixProductAfterI;
            productsExceptSelf.push_back(product);
        }

        return productsExceptSelf;
    }
};
