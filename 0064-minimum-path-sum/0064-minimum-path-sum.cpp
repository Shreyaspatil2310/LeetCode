class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
        int row = grid.size();
        int col = grid[0].size();

        if (i >= row || j >= col) return INT_MAX;
        
        if (i == row - 1 && j == col - 1) return grid[i][j];
        
        if (dp[i][j] != -1) return dp[i][j];

        int right = solve(grid, i, j + 1, dp);
        int down = solve(grid, i + 1, j, dp);
        
        dp[i][j] = grid[i][j] + min(right, down);
        return dp[i][j];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, -1));
        return solve(grid, 0, 0, dp);
    }
};
