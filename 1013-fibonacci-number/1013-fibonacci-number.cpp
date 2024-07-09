class Solution {
public:
   /* Recursion
    int fib(int n) {
        if(n<=1)
        return n;
        return fib(n-1)+fib(n-2);
    }*/
    int f(int n,vector<int>&dp){
        if(n<=1){
            return n;
        }
        if(dp[n]!=-1) return dp[n];
        return dp[n]=f(n-1,dp)+f(n-2,dp);
    }
    int fib(int n) {
        vector<int>dp(n+1,-1);
       return f(n,dp);
    }
};