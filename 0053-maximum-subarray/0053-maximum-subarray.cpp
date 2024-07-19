class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum= nums[0];
        int sum = 0;
        for(int i =0; i < nums.size() ; i++){
            if(sum >= 0){
                sum += nums[i];
            }
            else{
                sum = nums[i];
            }
            
            if(sum > maxSum)
                maxSum = sum;
            
        }
        return maxSum;
    
    }
};