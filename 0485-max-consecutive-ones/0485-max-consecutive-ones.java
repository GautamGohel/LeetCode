class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int cnt=0;
        int maxi=0;
        int n=nums.length;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                cnt++;
                maxi=Math.max(cnt,maxi);
            }
            else{
                cnt=0;
            }
        }
        return maxi;
    }
}