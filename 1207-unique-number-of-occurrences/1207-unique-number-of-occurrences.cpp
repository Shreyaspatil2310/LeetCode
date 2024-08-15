class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m, f;
        for (auto a : arr) {
            m[a]++;
        }
        for (auto v : m) {
            f[v.second]++;
            if (f[v.second] > 1) return false;
        }
        return true;
    }
};