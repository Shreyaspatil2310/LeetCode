#define inc()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        inc();
        int m = rolls.size();
        int sum = accumulate(rolls.begin(), rolls.end(), 0);
        int totalSum = (m + n) * mean;
        int reqSum = totalSum - sum;
        if (6 * n < reqSum || reqSum < n)
            return {};

        int base = reqSum / n;
        int increment = reqSum % n;
        vector<int> result(n, base);
        for (int i = 0; i < increment; i++) {
            result[i]++;
        }
        return result;
    }
};