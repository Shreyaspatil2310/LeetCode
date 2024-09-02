class Solution {
public:
    int solve(string &a, string &b, int i, int j, vector<vector<int>>&dp){
        int n = a.size();
        int m = b.size();
        if (i == n || j == m) return 0 ;

        if(dp[i][j] != -1) return dp[i][j];

        
        if (a[i] == b[j] ){
          return dp[i][j] =  1+ solve(a, b, i+1, j+1, dp);
        } 
        else{
           dp[i][j] = max(solve(a,b,i+1, j, dp) , solve(a,b,i, j +1, dp));
        }

       return dp[i][j] ;
    }
     
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size() + 1, vector<int>(text2.size()+1, -1));
        return solve( text1, text2 , 0 , 0 , dp); 
    }
};