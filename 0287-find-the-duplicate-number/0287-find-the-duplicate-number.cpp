class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       map<int,int>m;
        for (auto i : nums){
            m[i]++;
            if(m[i] == 2)return i;
        }
        
        return 0;
    }
};