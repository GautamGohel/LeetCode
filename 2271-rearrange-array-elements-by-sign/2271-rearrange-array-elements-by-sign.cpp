class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int posind=0,negind=1;
        int n=nums.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                ans[negind]=nums[i];
                negind+=2;
            }else{
                ans[posind]=nums[i];
                posind+=2;
            }
        }
        return ans;
    }
};