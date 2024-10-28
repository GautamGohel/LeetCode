class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int x=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
              x++;
            }
        }
        if(nums[0]<nums[n-1]) x++;
        return x<2;
    }
};