class Solution {
public:
    int solveTab(vector<vector<char>>& matrix, int &maxi) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
        for (int i = row - 1; i >= 0; i--) {
            for (int j = col - 1; j >= 0; j--) {
                int right = dp[i][j + 1];
                int diagonal = dp[i + 1][j + 1];
                int down = dp[i + 1][j];
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[0][0];
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        solveTab(matrix, maxi);
        return maxi * maxi;
    }
};
