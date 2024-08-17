class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=nums[0];
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
           if(cnt==0){
            ele=nums[i];
           }
           if(ele==nums[i]){
             cnt++;
           }else{
              cnt--;
           } 
        }
        return ele;
    }
};