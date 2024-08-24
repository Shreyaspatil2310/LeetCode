class Solution {
    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &dp) {
        int m = grid.size(), n = grid[0].size();
        
        if (i >= m || j >= n || grid[i][j] == 1) 
           return 0;
        if (dp[i][j] != -1) 

           return dp[i][j];

        if (i == m - 1 && j == n - 1) 
           return 1;

        return dp[i][j] = solve(grid, i + 1, j, dp) + solve(grid, i, j + 1, dp);
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(obstacleGrid, 0, 0, dp);
    }
};