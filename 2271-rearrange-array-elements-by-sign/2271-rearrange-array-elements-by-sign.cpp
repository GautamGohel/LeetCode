class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
    //brute force
    //  int n=nums.size();   
    // vector<int>pos;
    // vector<int>neg;
    // for(int i=0;i<n;i++){
    //     if(nums[i]<0){
    //         neg.push_back(nums[i]);
    //     }
    //     else{
    //         pos.push_back(nums[i]);
    //     }
    // }
    // vector<int>ans;
    // for(int i=0;i<neg.size();i++){
    //     ans.push_back(pos[i]);
    //     ans.push_back(neg[i]);
    // }
    // return ans;

      int n=nums.size();  
      vector<int>result(n,0);
      int pos=0;
      int neg=1;
      for(int i=0;i<nums.size();i++){
        if(nums[i]<0){
            result[neg]=nums[i];
            neg+=2;
        }
        else{
            result[pos]=nums[i];
            pos+=2;
        }
      }
      return result;
    }
};