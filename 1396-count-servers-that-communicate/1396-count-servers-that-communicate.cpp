class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>cntrowserver(m,0);
        vector<int>cntcolserver(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    cntrowserver[i]++;
                    cntcolserver[j]++;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 and (cntrowserver[i]>1 or cntcolserver[j]>1)){
                   cnt++;
                }
            }
        }
        return cnt;
    }
};