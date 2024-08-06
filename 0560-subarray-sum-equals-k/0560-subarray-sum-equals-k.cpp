class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = nums[0]; 
        int cnt = 0;
        if(nums.size() == 0 ){
            return 0;
        }
        if( nums.size() == 1 && nums[0] == k){
            return nums[0] ;
        }
        for(int i = 1 ; i < nums.size() ; i++) {
            sum += nums[i];
            if(sum != k){
                sum -= nums[i];
            }
            cnt++;

        }
        return cnt;
        
    }
};