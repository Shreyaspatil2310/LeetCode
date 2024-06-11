int left(vector<int>& nums,int target,int i)
{
    while(i >= 0 && nums[i] == target)
    {
        i--;
    }
    return i+1;
}
int right(vector<int>& nums,int target,int i)
{
    int n = nums.size();
    while(i < n && nums[i] == target)
    {
        i++;
    }
    return i-1;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n-1;

        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(nums[mid] == target)
            {
                start = left(nums,target,mid);
                end = right(nums,target,mid);
                return {start,end};
            }
            else if(nums[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return {-1,-1};
    }
};