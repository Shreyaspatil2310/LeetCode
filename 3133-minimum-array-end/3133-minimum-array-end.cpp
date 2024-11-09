class Solution {
public:
    string get(string s,long long n)
    {
        for(int i=s.size()-1;i>=0;i--)
        {
             if(n==0){
               
                return s;
            }
            
            if(s[i]=='0')
            {
                s[i]=n&1?'1':'0';
                n=n>>1;
            }
           
        }
        return s;
    }
    long long minEnd(int n, int x) {
        bitset<64>bits(x);
        string f=bits.to_string();
        string res=get(f,n-1);
         bitset<64>bits1(res);
        return bits1.to_ullong();

    }
};