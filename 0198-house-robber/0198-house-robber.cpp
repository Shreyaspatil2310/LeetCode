class Solution {
public:
    int solve(vector<int>& nums) {
        int n = nums.size();
        int prev2 = 0;
        int prev1 = nums[0];

        for (int i = 1; i < n; i++) {
            int incl = prev2 + nums[i];
            int excl = prev1;
            int ans = max(incl, excl);
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }

        // Case 1: Rob houses from the first to the second-to-last
        vector<int> first(nums.begin(), nums.end() - 1);

        // Case 2: Rob houses from the second to the last
        vector<int> second(nums.begin() + 1, nums.end());

        return max(solve(first), solve(second));
    }
};
