class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        for(int i=0;i<s.length()-1;i++){
            int n=i;
            for(int j=s.length()-1;j>i;j--){
                if(s[j]>s[n]){
                    n=j;
                }
            }
            if(n!=i){
                int temp=s[n];
                s[n]=s[i];
                s[i]=temp;
                return stoi(s);
            }
        }
        return num;
    }
};