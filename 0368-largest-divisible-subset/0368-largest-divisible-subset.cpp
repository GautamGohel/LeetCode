class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>hash(n);
        int lastind=0;
        int maxi=0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0 and dp[i]<1+dp[prev]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
                if(dp[i]>maxi){
                    maxi=dp[i];
                    lastind=i;
                }
            }
        }
        vector<int>ans;
        ans.push_back(nums[lastind]);
        while(lastind!=hash[lastind]){
            lastind=hash[lastind];
            ans.push_back(nums[lastind]);
        }
        return ans;
    }
};