class Solution {
    void dfs(vector<vector<int>> &g,vector<int> &vis,int i,int &n){
        vis[i]=1;
        for(auto &stone: g[i]){
            if(!vis[stone]){
                dfs(g,vis,stone,n);
            }
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<vector<int>> g(n);
        int a,b,c,d;
        for(int i=0;i<n;i++){
            a= stones[i][0],b=stones[i][1];
            for(int j=i+1;j<n;j++){
                c= stones[j][0],d=stones[j][1];
                if(a==c||b==d){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        vector<int> vis(n,0);
        int count=0;
        for(int i=0;i<n;i++){
           if(vis[i]==0){
            count++;
            dfs(g,vis,i,n);
           }
        }
        return n-count;
    }
};