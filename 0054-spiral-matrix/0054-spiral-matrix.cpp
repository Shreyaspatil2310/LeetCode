class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();

        int cnt = 0;
        int total = row * col;

        int startRow = 0;
        int startCol = 0;
        int endRow = row - 1;
        int endCol = col - 1;

        while(cnt < total) {
            for(int i = startCol; cnt < total && i <= endCol; i++) {
                ans.push_back(matrix[startRow][i]);
                cnt++;
            }
            startRow++;

            for(int i = startRow; cnt < total && i <= endRow; i++) {
                ans.push_back(matrix[i][endCol]);
                cnt++;
            }
            endCol--;

            for(int i = endCol; cnt < total && i >= startCol; i--) {
                ans.push_back(matrix[endRow][i]);
                cnt++;
            }
            endRow--;

            for(int i = endRow; cnt < total && i >= startRow; i--) {
                ans.push_back(matrix[i][startCol]);
                cnt++;
            }
            startCol++;
        }

        return ans;
    }
};
