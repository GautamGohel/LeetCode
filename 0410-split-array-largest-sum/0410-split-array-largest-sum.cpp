class Solution {
public:
    
    bool ispossible(vector<int>nums,int mid,int k){
        int total=0;
        int cnt=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mid) return false;
            if(total+nums[i]>mid){
                cnt++;
                total=nums[i];
                if(cnt>k){
                    return false;
                }
            }
            else{
                total+=nums[i];
            }
        }
        return true;
    }
   
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=*min(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            if(ispossible(nums,mid,k)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};