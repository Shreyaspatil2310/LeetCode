class Solution 
{
public:
    int minimumAddedCoins(vector<int>& coins, const int &target) 
    {
        int result = 0;
        sort(coins.begin(), coins.end());
        int tableVal = 0;
        int i = 0;
        while(i < coins.size())
        {
            if(tableVal >= target)
            {
                return result;
            }
            if(tableVal + 1 < coins[i])
            {
                tableVal = 2 * tableVal + 1;
                result++;
            }
            else
            {
                tableVal += coins[i];
                i++;
            }
        }
        while(tableVal < target)
        {
            tableVal = 2 * tableVal + 1;
            result++;
        }
        return result;

        // O(n*log(n)) time
        // O(1) space
    }
};