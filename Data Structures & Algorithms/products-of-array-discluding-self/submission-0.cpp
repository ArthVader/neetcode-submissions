class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> productsExceptSelf = {};

        int totalNums = nums.size();
        for(int i = 0; i < totalNums; ++i)
        {
            int product = 1;
            for(int j = 0; j < totalNums; ++j)
            {
                if(i == j)
                {
                    continue;
                }

                product *= nums[j];
            }

            productsExceptSelf.push_back(product);
        }

        return productsExceptSelf;
    }
};
