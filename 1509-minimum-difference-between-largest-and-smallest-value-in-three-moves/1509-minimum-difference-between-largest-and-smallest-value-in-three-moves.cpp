class Solution {
public:
    int minDifference(std::vector<int>& nums) {
        
        if (nums.size() <= 4) {
            return 0;
        }
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int min_diff = INT_MAX;
        for (int i = 0; i <= 3; ++i) {
            min_diff = std::min(min_diff, nums[n - 1 - (3 - i)] - nums[i]);
        }

        return min_diff;
    }
};
