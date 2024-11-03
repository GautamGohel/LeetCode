class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=nums[0];
        int n=nums.size();
        int cnt=1;
        for(int i=1;i<n;i++){
           if(cnt==0){
            ele=nums[i];
           }
           if(nums[i]==ele){
            cnt++;
           }else{
            cnt--;
           }
        }
        return ele;
    }
};