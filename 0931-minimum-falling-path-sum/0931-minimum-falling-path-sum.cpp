// class Solution {
// public:

//     int solve(vector<vector<int>>& matrix, int i , int j ,vector<vector<int>> & dp){
//         int row = matrix.size();
//         int col = matrix[0].size();

//         if (i >= row || j >= col  || j <0 ) return INT_MAX;

//         if (i == row - 1 ) return matrix[i][j];

//         if (dp[i][j] != -1) return dp[i][j] ;

//         int down  = solve(matrix , i + 1 , j , dp);
//         int right =  solve(matrix , i +1, j + 1 , dp);
//         int left = solve(matrix , i +1 , j - 1 , dp);

//         dp[i][j] = matrix[i][j] +  min(down , min(right , left));
//         return dp[i][j];
    
//     }

//     int solveTab(vector<vector<int>>& matrix, int i , int j){
//         vector<vector<int>>dp(row ,vector<int>(col, 0));



//     }





//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int row = matrix.size();
//         int col = matrix[0].size();
//         vector<vector<int>>dp(row , vector<int>(col , -1));
       
//         int min_sum = INT_MAX;
        
//         for (int j = 0; j < col; ++j) {
//             min_sum = min(min_sum, solve(matrix, 0, j, dp));
//         }

//         return min_sum;
//     }
// };

class Solution {
public:
    int solve(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp) {
        int row = matrix.size();
        int col = matrix[0].size();

        // If out of bounds, return a large value since this path is invalid
        if (i >= row || j < 0 || j >= col) return INT_MAX;

        // If we reach the bottom row, return the current cell's value
        if (i == row - 1) return matrix[i][j];

        // If already computed, return the stored value
        if (dp[i][j] != -1) return dp[i][j];

        // Compute the minimum path sum by moving down, down-left, and down-right
        int down = solve(matrix, i + 1, j, dp);
        int down_left = solve(matrix, i + 1, j - 1, dp);
        int down_right = solve(matrix, i + 1, j + 1, dp);

        // Store the minimum path sum in the dp array
        dp[i][j] = matrix[i][j] + min(down, min(down_left, down_right));

        return dp[i][j];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col, -1));

        int min_sum = INT_MAX;
        
        // Compute the minimum falling path sum starting from any element in the first row
        for (int j = 0; j < col; ++j) {
            min_sum = min(min_sum, solve(matrix, 0, j, dp));
        }

        return min_sum;
    }
};
