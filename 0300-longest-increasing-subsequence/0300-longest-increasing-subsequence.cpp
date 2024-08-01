class Solution {
public:
   
   //simple memoization with prevind shift of 1

    // int solve(int ind,vector<int>arr,int n,int prevind,vector<vector<int>>&dp){
    //     if(ind==n) return 0;
    //     if(dp[ind][prevind+1]!=-1) return dp[ind][prevind+1];
    //     int nottake=solve(ind+1,arr,n,prevind,dp);
    //     int take=INT_MIN;
    //      if(prevind==-1 or arr[ind]>arr[prevind]){
    //         take=1+solve(ind+1,arr,n,ind,dp);
    //      }
    //     return dp[ind][prevind+1]=max(nottake,take);
    // }
    
    // int lengthOfLIS(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<vector<int>>dp(n,vector<int>(n+1,-1));
    //     return solve(0,nums,n,-1,dp);
    // }
     
     //simple tabulation with prevind shift of 1
    
    // int lengthOfLIS(vector<int>& arr) {
    //     int n=arr.size();
    //     vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    //      for(int ind=n-1;ind>=0;ind--){
    //         for(int prevind=ind-1;prevind>=-1;prevind--){
    //             int nottake=dp[ind+1][prevind+1];
    //             int take=0;
    //             if(prevind==-1 or arr[ind]>arr[prevind]){
    //                 take=1+dp[ind+1][ind+1];
    //             }
    //             dp[ind][prevind+1]=max(take,nottake);
    //         }
    //      }
    //     return dp[0][0];
    // }

    //simple space optimization with prevind shift of 1 and ahead and curr arrays
    //tc O(n^2) sp O(n)
    // int lengthOfLIS(vector<int>& arr) {
    //     int n=arr.size();
    //     vector<int>ahead(n+1,0);
    //      for(int ind=n-1;ind>=0;ind--){
    //         vector<int>curr(n+1,0);
    //         for(int prevind=ind-1;prevind>=-1;prevind--){
    //             int nottake=ahead[prevind+1];
    //             int take=0;
    //             if(prevind==-1 or arr[ind]>arr[prevind]){
    //                 take=1+ahead[ind+1];
    //             }
    //             curr[prevind+1]=max(take,nottake);
    //         }
    //         ahead=curr;
    //      }
    //     return ahead[0];
    // }
    //for printing that largest subsequence
// #include <bits/stdc++.h>
// int longestIncreasingSubsequence(int arr[], int n)
// {
//     vector<int>dp(n,1),hash(n);
//     int maxi=0;
//     int lastind=0;
//     for(int i=1;i<n;i++){
//         hash[i]=i;
//         for(int prev=0;prev<i;prev++){
//             if(arr[prev]<arr[i] and dp[i]<dp[prev]+1){
//                 dp[i]=dp[prev]+1;
//                 hash[i]=prev;
//             }
//             if(dp[i]>maxi){
//                 maxi=dp[i];
//                 lastind=i;
//             }
//         }
//     }
//     vector<int>temp;
//     temp.push_back(arr[lastind]);
//     while(lastind!=hash[lastind]){
//         lastind=hash[lastind];
//         temp.push_back(arr[lastind]);
//     }
//     reverse(temp.begin(),temp.end());
//     return maxi;
// }

//using binary search lower bound
// tc_O(n) sp O(n)
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int>v;
        int len=1;
        v.push_back(arr[0]);
        for(int i=1;i<n;i++){
            if(v.back()<arr[i]){
                v.push_back(arr[i]);
                len++;
            }
            else{
            int ind=lower_bound(v.begin(),v.end(),arr[i])-v.begin();
            v[ind]=arr[i];
            }
        }
        return len;
    }
};