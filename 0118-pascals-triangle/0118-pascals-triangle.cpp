class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>finans;
        for(int i=1;i<=numRows;i++){
            vector<int>res;
           int ans=1;
            res.push_back(1);
           for(int j=1;j<i;j++){
              ans=ans*(i-j);
              ans=ans/j;
              res.push_back(ans);
           }
           finans.push_back(res);
        }
        return finans;
    }
};