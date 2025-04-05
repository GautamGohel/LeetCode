class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            int ptr1=i;
            int ptr2=i+1;
            int ptr3=n-1;
            if(ptr1!=0 and nums[ptr1]==nums[ptr1-1]) continue;
            while(ptr2<ptr3){
                int sum=nums[ptr1]+nums[ptr2]+nums[ptr3];
                if(sum==0){
                    ans.push_back({nums[ptr1],nums[ptr2],nums[ptr3]});
                    ptr2++;
                    ptr3--;
                    while(ptr2<ptr3 and nums[ptr2]==nums[ptr2-1]) ptr2++;
                    while(ptr2<ptr3 and nums[ptr3]==nums[ptr3+1]) ptr3--;
                }
                else if(sum<0){
                    ptr2++;
                }
                else{
                    ptr3--;
                }
            }
        }
        return ans;
    }
};