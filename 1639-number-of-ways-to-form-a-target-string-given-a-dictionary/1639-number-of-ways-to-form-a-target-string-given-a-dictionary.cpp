#define MOD 1000000007
#define ll long long

class Solution {
public:
    int solve(vector<string>& words, string& target, int i, int j, vector<vector<int>>& freq, vector<vector<int>>& dp) {
        if (j == target.length()) return 1;
        if (i == words[0].length()) return 0;

        if (dp[i][j] != -1) return dp[i][j]; 

        ll nt = solve(words, target, i + 1, j, freq, dp); // Skip current column
        ll t = ((ll)freq[i][target[j] - 'a'] * solve(words, target, i + 1, j + 1, freq, dp)) % MOD; // Use current column

        return dp[i][j] = (nt + t) % MOD;
    }

    int numWays(vector<string>& words, string target) {
        int m = words[0].length();
        vector<vector<int>> freq(m, vector<int>(26, 0));

        // Build frequency table
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < m; ++j) {
                freq[j][words[i][j] - 'a']++;
            }
        }

        vector<vector<int>> dp(m, vector<int>(target.size(), -1));
        return solve(words, target, 0, 0, freq, dp);
    }
};