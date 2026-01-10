class Solution {
    public void sortColors(int[] nums) {
        int n=nums.length;
        int s=0,e=nums.length-1,i=0;
        while(i<=e){
            if(nums[i]==0){
               int temp=nums[i];
               nums[i]=nums[s];
               nums[s]=temp;
               s++;
               i++;
            }
            else if(nums[i]==1){
               i++;
            }
            else if(nums[i]==2){
               int temp=nums[i];
               nums[i]=nums[e];
               nums[e]=temp;
               e--;
            }
        }
    }
}