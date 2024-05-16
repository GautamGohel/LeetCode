class Solution {
public:
    int binarysearch(vector<int>& nums, int target,int low,int high){
        
        if(low>high){
           return -1;
        }
        
        int n=nums.size();
       int mid=(low+high)/2;
        if(target==nums[mid]){
            return mid;
        }
        else if(target>nums[mid]){
           return binarysearch(nums,target,mid+1,high);
        }
        else {
            return binarysearch(nums,target,low,mid-1);
        }
        return -1;
    }
        
    int search(vector<int>& nums, int target) {
        /*
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(target==nums[mid]) return mid;
            else if(target>nums[mid]) low=mid+1;
            else high=mid-1;
        }
        return -1;
        */
        int n=nums.size();
        int low=0,high=n-1;
       return binarysearch(nums,target,low,high);
    }
};