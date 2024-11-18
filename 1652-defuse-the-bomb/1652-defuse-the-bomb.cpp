class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> answer(n);


        if (k == 0) {
            return vector<int>(n, 0);
        }
        // Traverse and evaluate
        for (int i = 0; i < n; i++) {
            long long sum = 0;
            if (k > 0) {
                // Sum the next k elements
                for (int j = 1; j <= k; j++) {
                    sum += code[(i + j) % n];
                }
            } else { // k < 0
                // Sum the previous |k| elements
                for (int j = 1; j <= -k; j++) {
                    sum += code[(i - j + n) % n]; // Ensure positive index
                }
            }
            answer[i] = sum;
        }
        return answer;
    }
};