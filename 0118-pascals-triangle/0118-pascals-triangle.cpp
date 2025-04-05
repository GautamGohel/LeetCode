class Solution {
public:

   long long calculatencr(int n,int r){
       long long res = 1;

    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
   }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>finans;
        for(int i=1;i<=numRows;i++){
            vector<int>ans;
            for(int j=1;j<=i;j++){
                long long res=calculatencr(i-1,j-1);
                ans.push_back(res);
            }
            finans.push_back(ans);
        }
        return finans;
    }
};