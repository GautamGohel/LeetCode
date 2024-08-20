class Solution {
public:

   int getfirstele(vector<int>nums,int target){
     int n=nums.size();
     int low=0,high=n-1;
     int res=-1;
     while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target){
            res=mid;
            high=mid-1;
        }
        else if(nums[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
     }
     return res;
   }

    int getlastele(vector<int>nums,int target){
        int n=nums.size();
        int res=-1;
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                res=mid;
                low=mid+1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return res;
   }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        ans.push_back(getfirstele(nums,target));
        ans.push_back(getlastele(nums,target));
        return ans;
    }
};