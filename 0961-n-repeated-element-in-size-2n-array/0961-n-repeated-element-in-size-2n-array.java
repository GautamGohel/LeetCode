class Solution {
    public int repeatedNTimes(int[] nums) {
        // Map<Integer,Integer>mp=new HashMap<>();
        // int n=nums.length;
        // for(int num:nums){
        //    mp.put(num,mp.getOrDefault(num,0)+1);
        //    if(mp.get(num)==n/2){
        //     return num;
        //    }
        // }
        // return -1;
        int n=nums.length;
        for(int i=0;i<n-2;i++){
           if(nums[i]==nums[i+1] || nums[i]==nums[i+2]){
              return nums[i];
           }
        }
        return nums[n-1];
    }
}