class Solution {
public:
    int fn(vector<int>&nums) {
    int n=nums.size();
    int prev2=0;
    int prev=nums[0];
        int ans;
        for(int i=1;i<n;i++){
           int pick=nums[i];
           if(i>1) pick+=prev2;
           int notpick=prev;
           ans=max(pick,notpick);
           prev2=prev;
           prev=ans;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int>temp1,temp2;
        for(int i=0;i<nums.size();i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=nums.size()-1) temp2.push_back(nums[i]);
        }
        return max(fn(temp1),fn(temp2));
    }
};