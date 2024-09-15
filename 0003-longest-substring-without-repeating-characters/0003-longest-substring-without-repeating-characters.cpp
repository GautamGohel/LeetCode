class Solution {
public:
    // int lengthOfLongestSubstring(string s) {
    //     int n=s.size();
    //     int maxlen=0;
    //     for(int i=0;i<n;i++){
    //         int hash[256]={0};
    //         for(int j=i;j<n;j++){
    //             if(hash[s[j]]==1){
    //                 break;
    //             }else{
    //                 maxlen=max(maxlen,j-i+1);
    //                 hash[s[j]]=1;
    //             }
    //         }
    //     }
    //     return maxlen;
    // }

    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int maxlen=0;
        int hash[256];
        fill(hash, hash + 256, -1); 
        int l=0,r=0;
        while(r<n){
           if(hash[s[r]!=-1]){
                if(hash[s[r]]>=l){
                    l=hash[s[r]]+1;
                }
            }
            maxlen=max(maxlen,r-l+1);
            hash[s[r]]=r;
            r++;
        }
        return maxlen;
    }
};