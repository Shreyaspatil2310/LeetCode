class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
         vector<pair<int, int>> ans;
    
    
    for (const auto& interval : intervals) {
        ans.push_back({interval[0], 1});    
        ans.push_back({interval[1] + 1, -1}); 
    }
    
    
    sort(ans.begin(), ans.end());
    
    int ma = 0;
    int a = 0;
    
   
    for (const auto& i : ans) {
        a += i.second;  
        ma = max(ma, a); 
    }
    
    return ma;
    }
};