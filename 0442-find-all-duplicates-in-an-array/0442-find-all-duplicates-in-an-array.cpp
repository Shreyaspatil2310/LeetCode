class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        for(int i=0;i<n;i++){
            if(mp[nums[i]]>1){
                ans.push_back(nums[i]);
                mp[nums[i]]--;
            }
        }
        return ans;
    }
};