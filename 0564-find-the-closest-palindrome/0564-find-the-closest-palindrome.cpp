class Solution {
public:
    string nearestPalindromic(string n) {
     int len = n.size();
        long long num = stoll(n), prefix = stoll(n.substr(0, (len + 1) / 2));
        vector<long long>k = {
            (long long)pow(10, len) + 1,     
            (long long)pow(10, len - 1) - 1  
        };
        
        for (int i = -1; i <= 1; ++i) {
            string p = to_string(prefix + i);
            string b = p + string(p.rbegin() + (len % 2), p.rend());
            k.push_back(stoll(b));
        }

        long long j = -1;
        for (long long a : k) {
            if (a != num && (j == -1 || abs(a - num) < abs(j - num) || 
               (abs(a - num) == abs(j - num) && a < j))) {
                j = a;
            }
        }
        
        return to_string(j);    
    }
};