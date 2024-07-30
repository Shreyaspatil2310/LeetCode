class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;
        // find the dip from right to left
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]) {
                ind = i;
                break;
            }
        }
        if(ind == -1){
            // there is no dip so reverse
            reverse(nums.begin(),nums.end());
        }else{
            // there is a dip so find ele which is greater than nums[ind] or the dip ele but smaller than rest of the elemetns in right side of dip ele and swap.
            for(int i=n-1;i>ind;i--){
                if(nums[i]>nums[ind]){
                    swap(nums[i],nums[ind]);
                    break;
                }
            }
            // then reverse form ind+1 to end;
            reverse(nums.begin()+ind+1,nums.end());
        }
    }
};