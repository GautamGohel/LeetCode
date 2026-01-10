class Solution {
    public int majorityElement(int[] nums) {
        Map<Integer,Integer>mp=new HashMap<>();
        int n=nums.length;
        for(int i=0;i<n;i++){
            mp.put(nums[i],mp.getOrDefault(nums[i],0)+1);
        }
        for(Integer nm:mp.keySet()){
            if(mp.get(nm)>n/2){
                return nm;
            }
        }
        return -1;
    }
}