
class Solution 
{

public:

    bool check(vector<int>& nums) 
    {
        const int size = nums.size();

        if (size > 1)
        {
            int count = 0;

            for (int i = 1 ; i < size ; i++)
            {
                if (nums[i - 1] > nums[i])
                {
                    count++;
                }
            }

            if (nums[size - 1] > nums[0])
            {
                count++;
            }

            return count < 2;
        }

        return true;
    }
};