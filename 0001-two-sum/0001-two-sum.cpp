class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //brute force using two for loops tc O(n2)

        // better approach 
        // using map tc O(nlogn) sc O(n)
        map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int val=nums[i];
            int rem=target-val;
            if(mp.find(rem)!=mp.end()){
                return {i,mp[rem]};
            }
            mp[val]=i;
        }
        return {-1,-1};
    }
};