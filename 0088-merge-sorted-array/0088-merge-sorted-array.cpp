class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        if(!nums1.empty()){
        for(int i = 0; i < m; i++){
                ans.push_back(nums1[i]);
        }
        }
        if(!nums2.empty()){
            for(int i = 0; i < n; i++){
                ans.push_back(nums2[i]);
        }
        }
        sort(ans.begin(), ans.end());
        nums1.clear();
        nums1 = ans;
        for(int i = 0; i < ans.size(); i++){
            cout<<ans[i]<<" "; 
        }
    }
};