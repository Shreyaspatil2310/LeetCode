class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int len1 = words1.size(), len2 = words2.size();

        // store maximum count of every letter, among all words2
        vector<int> maxCount2(26);
        for(int i=0; i<len2; i++){
            vector<int> count2(26);
            for(char &c:words2[i]) count2[c-'a']++;
            for(int j=0; j<26; j++) maxCount2[j] = max(maxCount2[j], count2[j]);
        }

        vector<string> res;
        // for a word in words1 to be universal, its every letter count should not be less than maximum count of that letter from words2 array
        for(int i=0; i<len1; i++){
            vector<int> count1(26);
            for(char &c:words1[i]) count1[c-'a']++;
            for(int j=0; j<26; j++){
                if(count1[j]<maxCount2[j]) break;
                if(j==25) res.push_back(words1[i]);
            }
        }
        return res;
    }
};