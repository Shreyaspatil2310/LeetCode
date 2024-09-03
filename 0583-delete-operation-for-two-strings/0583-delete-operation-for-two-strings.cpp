class Solution {
public:
 int solve(string& a, string& b, int i, int j, vector<vector<int>>& dp) {
        int n = a.length();
        int m = b.length();

        if (i == n || j == m) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (a[i] == b[j]) {
            dp[i][j] = 1 + solve(a, b, i + 1, j + 1, dp);
        } else {
           
            dp[i][j] = max(solve(a, b, i + 1, j, dp), solve(a, b, i, j + 1, dp));
        }
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int lps = solve(word1, word2, 0, 0, dp);
        return   (n- lps) + (m - lps);
        
    }
};