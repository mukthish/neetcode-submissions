class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int curr_profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            curr_profit += prices[i] - prices[i - 1];
            if (curr_profit < 0) {
                curr_profit = 0;
            }
            max_profit = max(curr_profit, max_profit);
        }
        return max_profit;
    }
};
