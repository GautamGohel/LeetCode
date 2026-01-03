class Solution {
    public int singleNumber(int[] nums) {
        int xorr=0;
        int n=nums.length;
        for(int i=0;i<n;i++){
            xorr=xorr^nums[i];
        }
        return xorr;
    }
}