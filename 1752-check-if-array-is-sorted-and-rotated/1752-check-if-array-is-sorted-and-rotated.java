class Solution {
    public boolean check(int[] nums) {
       int cnt=0;
       for(int i=0;i<nums.length-1;i++){
        if(nums[i]>nums[i+1]){
            cnt++;
        }
       } 
       if(nums[0]<nums[nums.length-1]){
        cnt++;
       }
       return cnt<=1;
    }
}