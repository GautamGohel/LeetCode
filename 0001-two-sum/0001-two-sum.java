class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n=nums.length;
        // for(int i=0;i<n;i++){
        //    for(int j=i+1;j<n;j++){
        //      if(nums[i]+nums[j]==target){
        //         return new int[]{i,j};
        //      }
        //    }
        // }
        // return new int[]{-1,-1};
        Map<Integer,Integer>mp=new HashMap<>();
        for(int i=0;i<n;i++){
            int rem=target-nums[i];
           if(mp.containsKey(target-nums[i])){
              return new int[]{mp.get(target-nums[i]),i};
           }
           mp.put(nums[i],i);
        }
        return new int[]{-1,-1};
    }
}