class Solution {
public:
    static bool customSort(int a, int b) {
        if (a < 0 && b < 0) {
            return a > b;
        } else if (a > 0 && b > 0) {
            return a < b;
        } else {
            return a < b;
        }
    }
    bool checkIfExist(vector<int>& arr) {
        unordered_map<double, int> m;
        sort(arr.begin(), arr.end(), customSort);
        for (int x : arr) {
            if (m.find((double)x / 2) != m.end()) {
                return true;
            }
            m[x]++;
        }
        return false;
    }
};