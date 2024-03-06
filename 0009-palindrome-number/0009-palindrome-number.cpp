class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int digit;
        int num=x;
        long long result=0;
        do
     {
         digit = num % 10;
         result = (result* 10) + digit;
         num = num / 10;
     } while (num != 0);
        if(result==x){
            return true;
        }
        else
        return false;
    }
};