class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0;
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
           if(nums[i]==1){
             cnt++;
           }else{
             maxi=max(maxi,cnt);
             cnt=0;
           }
        }
        maxi=max(maxi,cnt);
        return maxi;
    }
};