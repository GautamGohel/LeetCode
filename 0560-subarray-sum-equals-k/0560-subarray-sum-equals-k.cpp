class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       /*
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum==k) cnt++;
            }
        }
        return cnt;
        */
        int n=nums.size();
        map<int,int>mp;
        int sum=0;
        int cnt=0;
        for(int i=0;i<n;i++){
           sum+=nums[i];
           if(sum==k) cnt++;
           int rem=sum-k;
           if(mp.find(rem)!=mp.end()){
             cnt+=mp[rem];
           }
           mp[sum]++;
        }
        return cnt;
    }
};