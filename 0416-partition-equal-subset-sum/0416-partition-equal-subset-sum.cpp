class Solution {
public:
   
    bool canPartition(vector<int>& arr) {
        int sum=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(sum%2!=0) return false;
        int target=sum/2;
        vector<vector<bool>>dp(n,vector<bool>(target+1,false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(arr[0]<=target){
            dp[0][arr[0]]=true;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=target;j++){
                bool pick=false;
                if(arr[i]<=j){
                    pick=dp[i-1][j-arr[i]];
                }
                bool notpick=dp[i-1][j];
                dp[i][j]=pick or notpick;
            }
        }
        return dp[n-1][target];
    }
};