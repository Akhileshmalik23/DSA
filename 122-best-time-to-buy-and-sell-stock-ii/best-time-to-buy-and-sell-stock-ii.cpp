class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int profit = 0;
        int buy = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            int cur =  prices[i]-buy;
            if (cur <= 0)
                buy = prices[i];

            else {
                profit += cur;
                buy = prices[i];
            }
        }
        return profit;
    }
};