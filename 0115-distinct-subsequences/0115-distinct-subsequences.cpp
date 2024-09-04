class Solution {
public:
    int solve(string &a, string &b, int i, int j, vector<vector<int>>& dp) {
        int n = a.length();
        int m = b.length();

        // Base Case: If we have matched the entire string b
        if (j == m) return 1;

        // Base Case: If we have reached the end of string a without matching b completely
        if (i == n) return 0;

        // Check if result is already computed
        if (dp[i][j] != -1) return dp[i][j];

        // Recursive Case:
        if (a[i] == b[j]) {
            // Option 1: Include current character of a in the matching subsequence
            // Option 2: Exclude current character of a and continue
            dp[i][j] = solve(a, b, i + 1, j + 1, dp) + solve(a, b, i + 1, j, dp);
        } else {
            // If characters don't match, move forward in string a
            dp[i][j] = solve(a, b, i + 1, j, dp);
        }

        return dp[i][j];
    }
    
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(s, t, 0, 0, dp);
    }
};
