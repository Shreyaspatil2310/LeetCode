class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0){
            return false;
        }
        long long  palindrome=x;
        long long digit,rev=0; 
        while(x !=0){
            digit=x %10;
            x /= 10;
            rev= rev *10 + digit;
        }
        if (rev == palindrome){
            return true;
        }
        else{
            return false;
        }
    } 
};