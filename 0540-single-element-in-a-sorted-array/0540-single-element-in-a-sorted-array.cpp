class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=1,h=n-2;
        if(n==1){
            return nums[0];
        }
        if(nums[0]!=nums[1]){
            return nums[0];
        }
        if(nums[n-1]!=nums[n-2]){
            return nums[n-1];
        }
        while(l<=h){
           int mid=(l+h)/2;
           if(mid%2==0){
             if(nums[mid]!=nums[mid+1]){
                h=mid-1;
             }else{
                l=mid+1;
             }
           }else{
              if(nums[mid]!=nums[mid-1]){
                 h=mid-1;
              }else{
                l=mid+1;
              }
           }
        }
        return nums[l];
    }
};