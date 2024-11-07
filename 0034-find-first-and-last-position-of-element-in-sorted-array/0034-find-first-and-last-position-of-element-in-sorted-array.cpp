class Solution {
public:
 
    int firstocc(vector<int>&nums,int target){
        int n=nums.size();
        int l=0,h=n-1;
        int res=-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]==target){
               res=mid;
               h=mid-1;
            }else if(nums[mid]<target){
               l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return res;
    }

    int lastocc(vector<int>&nums,int target){
        int n=nums.size();
        int l=0,h=n-1;
        int res=-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]==target){
               res=mid;
               l=mid+1;
            }else if(nums[mid]>target){
               h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return res;
    }
  
    vector<int> searchRange(vector<int>& nums, int target) {
        return {firstocc(nums,target),lastocc(nums,target)};
    }
};