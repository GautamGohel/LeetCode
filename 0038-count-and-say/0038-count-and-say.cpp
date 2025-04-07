class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string s=countAndSay(n-1);
        int size=s.size();
        string ans;
        int cnt=1;
        for(int i=0;i<size;i++){
            cnt=1;
            while(i<size-1 and s[i]==s[i+1]){
                cnt++;
                i++;
            }
            ans+=to_string(cnt);
            ans+=s[i];
        }
        return ans;
    }
};