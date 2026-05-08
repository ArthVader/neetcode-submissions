class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;

        int buyDay = 0;
        int totalDays = prices.size();
        for(int sellDay = buyDay+1; sellDay < totalDays && buyDay < totalDays; ++sellDay)
        {
            if(prices[buyDay] > prices[sellDay])
            {
                buyDay = sellDay;
                cout << "buyDay" << buyDay;
            }
            else
            {
                maxProfit = max(maxProfit, prices[sellDay] - prices[buyDay]);
            }
        }
        
        return maxProfit;
    }
};
