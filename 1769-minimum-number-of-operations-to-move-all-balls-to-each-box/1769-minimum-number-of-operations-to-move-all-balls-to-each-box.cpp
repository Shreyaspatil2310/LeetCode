class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> res;
        int n = boxes.length();
        for (int i = 0, count = 0, x = 0; i < n; i++){
            res.push_back(count);
            x += boxes[i] - '0';
            count += x;
        }
        for (int i = n - 1, count = 0, x = 0; i >= 0; i--){
            res[i] += count;
            x += boxes[i] - '0';
            count += x;
        }
        return res;
    }
};