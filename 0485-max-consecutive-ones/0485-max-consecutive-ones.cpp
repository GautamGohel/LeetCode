class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int n=nums.size();
       int  maxi=0;
       int x=0;
       for(int i=0;i<n;i++){
         if(nums[i]==1){
            x++;
         }else{
            x=0;
         }
         if(x>maxi){
            maxi=x;
         }
       } 
    return maxi;
    }
};