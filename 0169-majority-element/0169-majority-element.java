class Solution {
    public int majorityElement(int[] nums) {
        int ele=nums[0];
        int cnt=0;
        int n=nums.length;
        for(int i=0;i<n;i++){
           if(cnt==0){
             ele=nums[i];
             cnt=1;
           }
           else if(nums[i]==ele){
              cnt++;
           }else if(nums[i]!=ele){
              cnt--;
           }
        }
        return ele;
    }
}