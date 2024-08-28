class Solution {
public:
    int R, C;
    vector<vector<int>> grid1, grid2;
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int res = 0;
        this->R = grid1.size(), this->C = grid1[0].size();
        this->grid1 = grid1, this->grid2 = grid2;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (this->grid2[i][j] == 1 && dfs(i, j)) res++;
            }
        }
        return res;
    }
    bool dfs(int i, int j) {
        if (i < 0 || j < 0 || i >= R || j >= C || grid2[i][j] == 0) return true;
        if (grid1[i][j] == 0) return false;
        grid2[i][j] = 0;
        bool up = dfs(i-1, j), down = dfs(i+1, j), left = dfs(i, j-1), right = dfs(i, j+1);
        return up && down && left && right;
    }
};