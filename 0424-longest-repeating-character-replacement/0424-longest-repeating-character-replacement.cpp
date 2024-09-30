class Solution {
public:
    // int characterReplacement(string s, int k) {
    //     int n = s.size();
    //     int maxlen = 0;
    //     for (int i = 0; i < n; i++) {
    //         int hash[26] = {0};
    //         int maxf = 0;       
    //         for (int j = i; j < n; j++) {
    //             hash[s[j] - 'A']++; 
    //             maxf = max(maxf, hash[s[j] - 'A']);
    //             int rem = j - i + 1 - maxf;
    //             if (rem <= k) {
    //                 maxlen = max(maxlen, j - i + 1);
    //             }
    //         }
    //     }
    //     return maxlen;
    // }

   int characterReplacement(string s, int k) {
        int n = s.size();
        int maxlen = 0;
        int maxf = 0;
        int l = 0, r = 0;
        int hash[26] = {0};
        while (r < n) {
            hash[s[r] - 'A']++;
            maxf = max(maxf, hash[s[r] - 'A']); 
            while ((r - l + 1) - maxf > k) {
                hash[s[l] - 'A']--; 
                l++; 
                maxf = 0;
                for (int i = 0; i < 26; i++) {
                    maxf = max(maxf, hash[i]);
                }
            }
            
            maxlen = max(maxlen, r - l + 1);
            r++; 
        }
        
        return maxlen;
    }
};
