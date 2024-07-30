class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int buy= prices[0];
        int gain =0;
        for(int i=1; i<n; i++){
            if(prices[i]<buy){
                buy=prices[i];
            }
            else if(prices[i]-buy>gain){
                gain=prices[i]-buy;
            } 
        }
    return gain;
    }
};