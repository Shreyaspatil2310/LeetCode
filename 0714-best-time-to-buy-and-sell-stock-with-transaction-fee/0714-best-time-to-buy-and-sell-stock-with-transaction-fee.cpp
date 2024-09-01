class Solution {
public:
    int solve(int index, int buy, vector<int>& prices, int fee, vector<vector<int>>& dp) {
        int n = prices.size();
        if (index == n) return 0;  
        if (dp[index][buy] != -1) return dp[index][buy];
        int profit = 0;
        if (buy) { 
            int buyStock = -prices[index] + solve(index + 1, 0, prices, fee, dp);
            int skipBuying = solve(index + 1, 1, prices, fee, dp);
            profit = max(buyStock, skipBuying);
        } else {
            
            int sellStock = prices[index] - fee + solve(index + 1, 1, prices, fee, dp);
            int skipSelling = solve(index + 1, 0, prices, fee, dp);
            profit = max(sellStock, skipSelling);
        }
        return dp[index][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, prices, fee, dp);
    }
};
