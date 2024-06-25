class Solution {
public:
    int singleNumber(vector<int>& nums) {
      /*  Sol-1 bitmanupulation
      int ans=0;
        for(int i=0;i<32;i++){
            int cnt=0;
           for(int j=0;j<nums.size();j++){
               if(nums[j]&(1<<i)){
                cnt++;
               }
           }
           if(cnt%3){
              ans=ans|(1<<i);
           }
        }
        return ans; */
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i+=3){
            if(nums[i]!=nums[i-1]){
                return nums[i-1];
            }
        }
        return nums[n-1];
    }
};