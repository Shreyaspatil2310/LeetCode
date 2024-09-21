class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int ch = 0;
        int co = 0;
        int cnt = 0;

        while (ch < g.size() && co < s.size()) {
            if (s[co] >= g[ch]) {
                cnt++;  
                ch++;  
            }
            co++;
        }
        return cnt;  
    }
};
