class Solution {
public:
    bool isPalindrome(string s) {
        char res[s.size()];
        int x=0;
        for(int i=0;i<s.size();i++)
        {
            if (isalpha(s[i]) || isdigit(s[i]))
            {
                res[x]=tolower(s[i]);
                x++;
            }
        }
        for(int i=0,j=x-1;i<=(x)/2,j>=(x)/2;i++,j--)
        {
            if(res[i]!=res[j])
            return 0;
        }
        return 1;
    }
};