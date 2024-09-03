class Solution {
public:
    int solve(string& a, string& b, int i, int j, vector<vector<int>>& dp) {
        int n = a.length();
        int m = b.length();

        // Base case: if either string is exhausted, return 0
        if (i == n || j == m) return 0;

        // If result is already computed, return it
        if (dp[i][j] != -1) return dp[i][j];

        // If characters match, move both pointers and add 1 to the result
        if (a[i] == b[j]) {
            dp[i][j] = 1 + solve(a, b, i + 1, j + 1, dp);
        } else {
            // If characters don't match, try both possibilities
            dp[i][j] = max(solve(a, b, i + 1, j, dp), solve(a, b, i, j + 1, dp));
        }

        return dp[i][j];
    }

    int minInsertions(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        int n = s.length();

        // dp[i][j] will store the length of the longest common subsequence between s[0..i-1] and rev[0..j-1]
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        // Find the length of the longest palindromic subsequence
        int lps = solve(s, rev, 0, 0, dp);

        // Minimum insertions needed = length of string - length of longest palindromic subsequence
        return n - lps;
    }
};
