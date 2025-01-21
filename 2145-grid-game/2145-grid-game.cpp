class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();
        long long remrow1sum=0;
        for(int i=0;i<n;i++){
            remrow1sum+=grid[0][i];
        }
        long long row2sum=0;
        long long mini=LLONG_MAX;
        for(int i=0;i<n;i++){
            remrow1sum-=grid[0][i];
            long long maxi=max(remrow1sum,row2sum);
            mini=min(mini,maxi);
            row2sum+=grid[1][i];
        }
        return mini;
    }
};