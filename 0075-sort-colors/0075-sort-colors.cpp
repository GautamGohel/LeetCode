class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int s=0,mid=0,end=n-1;
        while(mid<=end){
            if(nums[mid]==0){
                swap(nums[mid],nums[s]);
                s++;
                mid++;
            }else if(nums[mid]==1){
                mid++;
            }else{
                swap(nums[mid],nums[end]);
                end--;
            }
        }
    }
};