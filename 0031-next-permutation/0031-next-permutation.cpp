class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         if (std::next_permutation(nums.begin(), nums.end())) {
        std::cout << "Next permutation: ";
    } else {
        std::cout << "Array is in the highest permutation, reset to lowest permutation: ";
    }
        
    }
};