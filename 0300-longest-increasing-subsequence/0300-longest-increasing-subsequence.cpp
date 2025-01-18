class Solution {
public:
   
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>ahead(n+1,0);
        for(int ind=n-1;ind>=0;ind--){
            vector<int>curr(n+1,0);
           for(int prevind=ind-1;prevind>=-1;prevind--){
              int take=0;
              if(prevind==-1 or nums[prevind]<nums[ind]){
                  take=1+ahead[ind+1];
              }
              int nottake=ahead[prevind+1];
              curr[prevind+1]=max(take,nottake);
           }
           ahead=curr;
        }
        return ahead[0];
    }
};