class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        mp[0]=1;
        int n=nums.size();
        int presum=0;
        int cnt=0;
        for(int i=0;i<n;i++){
           presum+=nums[i];
           int rem=presum-k;
           cnt+=mp[rem];
           mp[presum]++;
        }
        return cnt;
    }
};