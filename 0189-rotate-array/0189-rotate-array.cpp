class Solution {
public:
    void rotate(vector<int>& nums, int k) {

       //brute force tc O(n) sc O(n)
        // int n = nums.size();
        // k=k%n;
        // vector<int> temp(n);
        // int j =n-k;
        // for (int i = 0; i < n; i++) {
        //    temp[i] = nums[j % n];
        //     j++;
        //  }
        //  nums = temp;
         
         //optimized space tc O(n)
          int n=nums.size();
          k=k%n;
          reverse(nums.begin(),nums.end());
          reverse(nums.begin(),nums.begin()+k);
          reverse(nums.begin()+k,nums.end());
    }
};