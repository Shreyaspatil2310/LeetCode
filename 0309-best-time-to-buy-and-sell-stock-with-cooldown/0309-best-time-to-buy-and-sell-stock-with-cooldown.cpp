class Solution {
public:
int soln(int ind,vector<int> &prices, bool buy,vector<vector<int>> &dp){
        if(ind>=prices.size()){
            return 0;
        }
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        
        if(buy){
            return dp[ind][buy]=max(
                -prices[ind]+soln(ind+1,prices,false,dp),
                0+soln(ind+1,prices,true,dp)
            );
        }
        else{
            return dp[ind][buy]=max(
                +prices[ind]+soln(ind+2,prices,true,dp),
                0+soln(ind+1,prices,false,dp)
            );
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+2,vector<int>(2,-1));
        return soln(0,prices,true,dp);
    }
};