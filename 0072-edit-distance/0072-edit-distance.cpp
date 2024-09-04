class Solution {
public:
    int solve(string &a, string &b, int i, int j, vector<vector<int>>& dp) {
        int n = a.length();
        int m = b.length();
        
        // Base Case: If we have exhausted word1, we need to insert remaining characters of word2
        if (i == n) return m - j;
        
        // Base Case: If we have exhausted word2, we need to delete remaining characters of word1
        if (j == m) return n - i;
        
        // Check if result is already computed
        if (dp[i][j] != -1) return dp[i][j];
        
        // If characters match, no operation is needed, move to the next characters in both strings
        if (a[i] == b[j]) {
            dp[i][j] = solve(a, b, i + 1, j + 1, dp);
        } else {
            // If characters don't match, consider all three operations:
            // 1. Insert: match b[j] with a[i], so move j forward
            int insertOp = 1 + solve(a, b, i, j + 1, dp);
            
            // 2. Delete: remove a[i], so move i forward
            int deleteOp = 1 + solve(a, b, i + 1, j, dp);
            
            // 3. Replace: replace a[i] with b[j], so move both i and j forward
            int replaceOp = 1 + solve(a, b, i + 1, j + 1, dp);
            
            // Take the minimum of the three operations
            dp[i][j] = min({insertOp, deleteOp, replaceOp});
        }
        
        return dp[i][j];
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(word1, word2, 0, 0, dp);
    }
};
