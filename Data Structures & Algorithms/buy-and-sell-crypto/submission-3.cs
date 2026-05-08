public class Solution {
    public int MaxProfit(int[] prices) {
        int maxProfit = 0;

        int buyDay = 0;
        for(int sellDay = buyDay+1; sellDay < prices.Length && buyDay < prices.Length; ++sellDay)
        {
            if(prices[buyDay] > prices[sellDay])
            {
                buyDay = sellDay;
            }
            else
            {
                maxProfit = Math.Max(maxProfit, prices[sellDay] - prices[buyDay]);
            }
        }

        return maxProfit;
    }
}
