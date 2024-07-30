class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); ++i) {
            if (res.empty() || res.back()[1] < arr[i][0]) {
                res.push_back(arr[i]);
            } else {
                res.back()[1] = max(res.back()[1], arr[i][1]);
            }
        }

        return res;
    }
};