class Solution {
public:
    const int mod = 1e9+7;
    int dp[100001];

    int solve(int low,int high,int zero,int one,int len){
        if(len > high) return 0;
        if(dp[len] != -1) return dp[len];

        int ans = (len >= low) ? 1 : 0;
        ans = (ans + solve(low,high,zero,one,len+zero)) % mod;
        ans = (ans + solve(low,high,zero,one,len+one)) % mod;

        return dp[len] = ans;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp, -1, sizeof(dp));
        return solve(low,high,zero,one,0);
    }
};