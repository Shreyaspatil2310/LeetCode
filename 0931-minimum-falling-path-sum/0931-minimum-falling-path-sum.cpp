class Solution {
public:
    int path_memo_helper(vector<vector<int>>&matrix,int i,int j,int& n,int& m,vector<vector<int>>&dp){
        if(i==n)return 0;
        int ans=1e9;
        vector<int>dir={-1,0,1};
        if(dp[i][j]!=-1)return dp[i][j];
        for(int k=0;k<3;k++){
            if(j+dir[k]>=0 && j+dir[k]<m){
                ans=min(ans,matrix[i][j]+path_memo_helper(matrix,i+1,j+dir[k],n,m,dp));
            }
        }
        return dp[i][j]=ans;
    }

    int path_memoization(vector<vector<int>>& matrix){
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=1e9;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int j=0;j<m;j++){
            ans=min(ans,path_memo_helper(matrix,0,j,n,m,dp));
        }
        return ans;
    }
  

    int path_tabulation(vector<vector<int>>&matrix){
          int n=matrix.size();
          int m=matrix[0].size();
          vector<vector<int>>dp(n,vector<int>(m,0));
          for(int i=0;i<m;i++)dp[0][i]=matrix[0][i];
          for(int i=1;i<n;i++){
              for(int j=0;j<m;j++){
                  dp[i][j]=dp[i-1][j]+matrix[i][j];
                  if(j-1>=0)dp[i][j]=min(dp[i][j],matrix[i][j]+dp[i-1][j-1]);
                  if(j+1<m)dp[i][j]=min(dp[i][j],matrix[i][j]+dp[i-1][j+1]);
              }
          }
          int fans=1e9;
          for(int j=0;j<m;j++)fans=min(fans,dp[n-1][j]);
          return fans;
    }

     int path_spaceOptimized(vector<vector<int>>&matrix){
          int n=matrix.size();
          int m=matrix[0].size();
          vector<int>dp(m,0);
          for(int i=0;i<m;i++)dp[i]=matrix[0][i];
          for(int i=1;i<n;i++){
              vector<int>curr=dp;
              for(int j=0;j<m;j++){
                  dp[j]=curr[j]+matrix[i][j];
                  if(j-1>=0)dp[j]=min(dp[j],matrix[i][j]+curr[j-1]);
                  if(j+1<m)dp[j]=min(dp[j],matrix[i][j]+curr[j+1]);
              }
          }
          int fans=1e9;
          for(int j=0;j<m;j++)fans=min(fans,dp[j]);
          return fans;
    }



    int minFallingPathSum(vector<vector<int>>& matrix) {
      return path_memoization(matrix);
    //    return path_tabulation(matrix);
    //    return path_spaceOptimized(matrix);
    }
};