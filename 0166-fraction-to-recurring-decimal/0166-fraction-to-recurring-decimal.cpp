class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        
        string ans;
        ans = (numerator > 0)^(denominator > 0) ? "-":"";       //adding sign if either num or deno is -ve
        
        long n = abs(numerator);        //making both num and deno +ve
        long d = abs(denominator);
        ans += to_string(n/d);          
        
        n = n%d;
        if(!n) return ans;              //if we got remainder n = 0 then return ans else add "." to the ans
        
        ans += ".";
        
        //If you find remainder again means ans from that point will start repeating from there so we map
        //remainder with the length pf answer at that point so that if it occur again then we can insert bracket there
        unordered_map<long, int> mp;
        
        while(n)        //repeat untill remainder != 0
        {   
            if(mp[n])   //if you find that this remainder has occurred before then  
            {
                ans.insert(mp[n], "(");    //Inserting ( at position when we first found that remainder
                ans += ")";                //Inserting closing bracket at the last
                break;          
            }
            else{
                mp[n] = ans.size();     //storing when remainder n come then what is the size of ans
                n *= 10;
                ans += to_string(n/d);  
                n = n%d;                //calculating remainder
            }
        }
        
        return ans;
    }
};