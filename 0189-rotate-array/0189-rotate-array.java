class Solution {

    void reverseTill(int[] nums,int s,int e){
        while(s<e){
            int temp=nums[s];
            nums[s++]=nums[e];
            nums[e--]=temp;
        }
    }

    public void rotate(int[] nums, int k) {
        int n=nums.length;
        k=k%n;
        if(n==0) return;
        reverseTill(nums,0,n-k-1);
        reverseTill(nums,n-k,n-1);
        reverseTill(nums,0,n-1);
    }
}