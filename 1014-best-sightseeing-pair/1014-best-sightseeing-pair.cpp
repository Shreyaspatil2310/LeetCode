class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n= values.size();
        vector<int> lastMax(n); // at jth index store maximum of (arr[i]-i) for i>=j and i<n.
        lastMax[n-1]=values[n-1]-n+1;
        values[n-1]+=(n-1);// update by adding index to corresponding element.
        for(int i=n-2;i>=0;i--){
            lastMax[i]= max(lastMax[i+1],values[i]-i);
            values[i]+=i;
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            ans=max(ans,values[i]+lastMax[i+1]);// final answer is maximum of arr[i]+lastMax[i+1]
        }
        return ans;
    }
};