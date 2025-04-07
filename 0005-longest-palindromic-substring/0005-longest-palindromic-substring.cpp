class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if (n < 2) return s;
        string LPS="";
        for(int i=1;i<n;i++){
            int l=i;
            int h=i;
            while(s[l]==s[h]){
                l--;
                h++;
                if(l==-1 or h==n) break;
            }
            string palindrom=s.substr(l+1,h-l-1);
            if(palindrom.size()>LPS.size()){
                LPS=palindrom;
            }
            l=i-1;
            h=i;
            while(s[l]==s[h]){
                l--;
                h++;
                if(l==-1 or h==n) break;
            }
            palindrom=s.substr(l+1,h-l-1);
            if(palindrom.size()>LPS.size()){
                LPS=palindrom;
            }
        }
        return LPS;
    }
};