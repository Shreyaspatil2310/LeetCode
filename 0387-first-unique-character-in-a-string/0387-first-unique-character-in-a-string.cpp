class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mapp(26);
        for(int i=0;i<s.size();i++){
            mapp[s[i]]++;
        }
        for(int i=0;i<s.size();i++){
            if(mapp[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};