class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n=arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int rem=target-arr[i];
            if(mp.find(rem)!=mp.end()){
                return {i,mp[rem]};
            }
            mp[arr[i]]=i;
        }
        return {-1,-1};
    }
};