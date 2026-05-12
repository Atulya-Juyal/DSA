class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minimal = prices[0];

        for(int i = 0; i < prices.size(); i++){
            int cost = prices[i] - minimal;
            profit = max(profit, cost);

            minimal = min(minimal, prices[i]);
        }

        return profit;
    }
};