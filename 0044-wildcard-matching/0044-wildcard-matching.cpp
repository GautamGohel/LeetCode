class Solution {
public:
    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();
        vector<bool> prev(n2 + 1, false);
        prev[0] = true;
        for (int j = 1; j <= n2; j++) {
            if (p[j - 1] == '*') {
                prev[j] = prev[j - 1];
            }
        }
        for (int i = 1; i <= n1; i++) {
            vector<bool>curr(n2+1,false);
            for (int j = 1; j <= n2; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    curr[j] = prev[j - 1];
                } else if (p[j - 1] == '*') {
                    curr[j] = curr[j - 1] || prev[j];
                } else {
                    curr[j] = false;
                }
            }
            prev=curr;
        }
        return prev[n2];
    }
};
