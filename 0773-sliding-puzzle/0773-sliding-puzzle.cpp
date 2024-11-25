class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_map<int,vector<int>> mp;
        mp[0]={1,3};
        mp[1]={0,2,4};
        mp[2]={1,5};
        mp[3]={0,4};
        mp[4]={1,3,5};
        mp[5]={4,2};
        string use="";
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                use+=to_string(board[i][j]);
            }
        }
        unordered_set<string> states;
        queue<pair<string,int>> q;
        q.push({use,0});
        while(!q.empty()){
            string s=q.front().first;
            int count=q.front().second;
            q.pop();
            if(s=="123450"){
                return count;
            }
            int posZ=s.find("0");
            for(int a: mp[posZ]){
                swap(s[posZ],s[a]);
                if(states.find(s)==states.end()){
                    q.push({s,count+1});
                    states.insert(s);    
                }
                swap(s[posZ],s[a]);
            }
        }
        return -1;
    }
};