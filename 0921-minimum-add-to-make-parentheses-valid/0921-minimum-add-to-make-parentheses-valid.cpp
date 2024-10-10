class Solution {
public:
    
    int minAddToMakeValid(string s) {
        stack<char> stac;
        for(char c : s)
        {
            if(!stac.empty() && stac.top()=='(' && c==')')stac.pop();
            else stac.push(c);
        }
        return stac.size();
    }
};