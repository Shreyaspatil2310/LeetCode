class Solution {
    vector<vector<int>> ans;
private:
    void f(int ind, int target, vector<int>& temp, vector<int>& arr){
        int n = arr.size();
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(ind==n){
            return;
        }

        for(int i=ind; i<n; i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;

            temp.push_back(arr[i]);
            f(i+1,target-arr[i],temp,arr);
            temp.pop_back(); // backtracking
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ans.clear();
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        f(0,target,temp,candidates);
        return ans;
    }
};