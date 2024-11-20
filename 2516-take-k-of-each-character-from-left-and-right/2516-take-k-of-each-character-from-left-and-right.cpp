class Solution {
public:
    int maxTime = INT_MIN;
    int takeCharacters(string s, int k) {
        int n = s.size();
        int a = 0, b = 0, c = 0;
        //Count the freqn's of a , b and c
        for(auto ch : s){
            if(ch == 'a')a++;
            else if(ch == 'b')b++;
            else c++;
        }
        if(a < k || b < k || c < k)return -1;
        
        int A = a - k, B = b - k, C = c - k;//max freqnc's of a , b and c that may accommodate in our window
        
        int j = 0;
        int ct_A = 0, ct_B = 0, ct_C = 0;
        //Sliding window approach
        for(int i = 0;i < n;i++){
            if(s[i] == 'a')ct_A++;
            else if(s[i] == 'b')ct_B++;
            else ct_C++;
            
            while(j <= i && (ct_A > A || ct_B > B || ct_C > C)){
                    if(s[j] == 'a')ct_A--;
                    else if(s[j] == 'b')ct_B--;
                    else ct_C--;
                    
                    j++;
            }
            maxTime = max(maxTime, (i - j + 1));
            
        }
        return n - maxTime; //result
    }
};